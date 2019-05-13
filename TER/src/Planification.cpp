#include "../include/Planification.h"

int **matrice_adjacence_GNO (int N, float K)
{
	int **T = (int**)malloc(N*sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		T[i] = (int*) malloc(N*sizeof(int));
	}
	int x = 0;
	srand(time(NULL));
	for (int j = 0; j < N; j++)
	{
		for(int i = j; i < N; i++)
		{
			x = rand()%100;
			if ((x <= (K*100)) && (i !=j))
			{
				T[i][j] = 1;
				T[j][i] = 1;
			}
			else
			{
				T[i][j] = 0;
				T[j][i] = 0;
			}
		}
	}
	return T;
}

//pas besoin de fonction pour orienter le graphe suffis de lire la matrice d'adjacence en escalier c'est facile
//je fais ca dans matrice_graphe_oriente

int *coloration (int N, int Nb)
{
	int *T = (int*)malloc(N*sizeof(int*));
	int couleur = 0;
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		couleur = rand()%(Nb);
		T[i] = couleur;
	}
	return T;
}

int trouver_degre_entrant_nul (int **T, int N)
{
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(T[i][j] != 0)
			{
				j = 1000;
			}
			else if(j == N-1)
			{
				return i;
			}
		}
	}
	perror("Erreur ce n'est pas un DAG" ); 
 	exit(0);
}

int **matrice_graphe_oriente (int **T, int N)
{
	int **TO = (int**)malloc(N*sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		TO[i] = (int*) malloc(N*sizeof(int));
	}
	for (int j = 0; j < N; j++)
	{
		for(int i = j; i < N; i++)
		{
			if(T[i][j] == 1)
			{
				TO[i][j] = 1;
			}
			else 
			{
				TO[i][j] = 0;
			}
		}
	}
	return TO;
}

//0 un TD, 1 un CM
int *type_cours (int N)
{
	int type = 0;
	int *T = (int*)malloc(N*sizeof(int*));
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		type = rand()%100;
		if (type <= 75)
		{
			T[i] = 0;
		}
		else
		{
			T[i] = 1;
		}
	}
	return T;
}

int *nb_eleves (int *TYPE, int N)
{
	int nb = 0;
	int *T = (int*)malloc(N*sizeof(int*));
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		if(TYPE[i] == 0)
		{
			nb = (rand()%16) + 16;
			T[i] = nb;
		}
		else
		{
			nb = (rand()%84) + 16;
			T[i] = nb;
		}
	}
	return T;
}

int plusGrand(int* T, int i, int j){
	int grand = T[i];
	int indice = i;
	for(int k = i; k < j; k++){
		if(T[k] > grand){
			grand = T[k];
			indice = k;
		}
	}
	return indice;
}

int* tabCours(int* nbEleves, int N){
	int *tabNbEleveDesc = (int*)malloc(N*sizeof(int*));;
	int indice = 0;
	int temp;
	printf("Cours avec le plus d'élèves -> moins d'élèves\n");
	for(int i = 0; i < N; i++){
		indice = plusGrand(nbEleves, i, N);
		tabNbEleveDesc[i] = indice;
		// printf("%d ", T[i]);
		temp = nbEleves[i];
		nbEleves[i] = nbEleves[indice];
		nbEleves[indice] = temp;
	}
	return tabNbEleveDesc;
}

bool test_coloration(int *Horaires, int *couleur, int N, int *TYPE, int heure_a_teste, int sommet_a_teste)
{
	int duree1 = 0;
	int duree2 = 0;
	//int Test[N];
	for(int i = 0; i < N; i++)
	{
		if((couleur[i] == couleur[sommet_a_teste])&& (sommet_a_teste != i))
		{
			if(TYPE[i] == 0){duree1 = 12;}else{duree1 = 6;}
			if(TYPE[sommet_a_teste] == 0){duree2 = 12;}else{duree2 = 6;}
			if(((heure_a_teste + duree2 >= Horaires[i]) &&  (heure_a_teste + duree2 <= Horaires[i] + duree1)) 
				|| ((Horaires[i] + duree1 >= heure_a_teste) && (Horaires[i] <= heure_a_teste + duree2)))
			{
				return false;
			}
		}
	}


		//if(TYPE[i] == 0){duree = 12;}else{duree = 6;}
		/*if((heure_a_teste >= Horaires[i]) && (heure_a_teste <= Horaires[i] + duree) && (sommet_a_teste != i))
		{
			//Test[i] = couleur[i];
			return false;
		} */
		/*else
		{
			Test[i] = 100;
		}
	}

	for(int i = 0; i < N; i++)
	{
		if((Test[i] == couleur[sommet_a_teste]) && (i!=sommet_a_teste) && (Test[i] != 100))
		{
			return false;
		}
	}*/
	return true;
}


bool testConnnexe(int **T, int N, int sommet){
	int degre = 0;
	for(int i = 0; i < N; i ++){
		degre += T[sommet][i];
	}
	for(int i = 0; i < N; i++){
		degre += T [i][sommet];
	}
	if (degre != 0){
		//printf("sommet %d connexe\n", sommet);
		return true;
	}
	//printf("sommet %d non connexe\n", sommet);
	return false;

}

bool test_lien(int *Horaires, int N, int **T, int heure_a_teste, int sommet_a_teste, int *TYPE)
{
	int duree = 0;
	for (int i = 0; i < N; i++)
	{
		if(TYPE[i] == 0) { duree = 12;} else {duree = 6;}
		if((T[sommet_a_teste][i] == 1) && (heure_a_teste >= Horaires[i]) && (heure_a_teste <= Horaires[i] + duree) && (sommet_a_teste != i))
		{
			//printf("false test lien\n");
			return false;
		}
	}
	//printf("true test lien\n");
	return true;
}

//Pour le moment TD c'est 3h et CM 1h30, a changer ptet je sais pas 
//Pour représenter les heures par créneau de 15 min :
//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34: indices
//    8       9       10          11          12          13          14          15          16: heure
int *planification(int **T, int sommet_depart, int *couleur, int N, int *TYPE)
{
	int *Horaires = (int*)malloc(N*sizeof(int*));
	Horaires[sommet_depart] = 0;
	for (int i = 0; i < N; i++)
	{
		Horaires[i] = 0;
		//c
	}

	for(int i = 1; i < N; i++)
	{
		for(int k = 0; k < N; k++)
		{
			if(T[i][k] == 1)
			{
				if(TYPE[i] == 0)//si le cours est un td
				{
					for(int j = 0; j <= 36; j++)
					{
						if(test_coloration(Horaires, couleur, N, TYPE, Horaires[k] + 13 + j, i) == true)
						{
							if(test_lien(Horaires, N, T, Horaires[k] + 13 + j, i, TYPE) == true)
							{
								Horaires[i] = Horaires[k] + 13 + j;
								//printf("Horaire de %d : %d\n",i,Horaires[i]);
								break;
							}
						}
					}

				}
				else //si le cours est un cm
				{
					for(int j = 0; j <= 36; j++)
					{
						if(test_coloration(Horaires, couleur, N, TYPE, Horaires[k] + 7 + j,i) == true)
						{
							if(test_lien(Horaires, N, T, Horaires[k] + 7 + j, i, TYPE) == true)
							{
								Horaires[i] = Horaires[k] + 7 + j;
								//printf("Horaire de %d : %d\n",i,Horaires[i]);
								break;
							}
						}
					}
				}
			}
			else {
				if(testConnnexe(T, N, i) == true){
					if(TYPE[k] == 0)//si le cours est un td
					{
						for(int j = 0; j <= 36; j++)
						{
							if(test_coloration(Horaires, couleur, N, TYPE, Horaires[k] + 13  + j, i) == true)
							{
								if(test_lien(Horaires, N, T, Horaires[k] + 13 + j, i, TYPE) == true)
								{
									Horaires[i] = Horaires[k] + 13 + j;
									//printf("Horaire de %d : %d\n",i,Horaires[i]);
									break;
								}
							}
						}
					}
					else //si le cours est un cm
					{
						for(int j = 0; j <= 36; j++)
						{
							if(test_coloration(Horaires, couleur, N, TYPE, Horaires[k] + 7 + j,i) == true)
							{
								if(test_lien(Horaires, N, T, Horaires[k] + 7 + j, i, TYPE) == true)
								{
									Horaires[i] = Horaires[k] + 7 + j;
									//printf("Horaire de %d : %d\n",i,Horaires[i]);
									break;
								}
							}
						}
					}
				}
			}	
		}
	}
	for (int i = 0; i < N; i++)
	{
		Horaires[i] += 2;
	} 
	return Horaires;
}

bool test_solution_valide(int *Horaires, int N, int *couleur, int *TYPE, int **TO)
{	
	//TEST COLORATION
	int dureei, dureej;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			
			if((couleur[i] == couleur[j]) && (i != j)) {
				
				if(TYPE[i] == 0) {dureei = 13;} else {dureei = 7;}
				if(TYPE[j] == 0) {dureej = 13;} else {dureej = 7;}
			if(Horaires[i] > Horaires[j]){
				
					if(Horaires[j] +dureej > Horaires[i])
					{
						//printf("Erreur couleur : %d et %d\n",i,j);
						return false;	
					}		
				}
				else {
					
					if(Horaires[i] + dureei > Horaires[j])
					{
						//printf("Erreur couleur : %d et %d\n",i,j);
						return false;
					}
				}
			}
		}
	}
	//printf("return true color\n");

	//TEST LIEN
	int duree = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			if(TO[i][j] == 1) {
				if(TYPE[j] == 0) duree = 12; else duree = 6;
			if((test_lien(Horaires, N, TO, Horaires[i] + duree, j, TYPE) == false) && (i != j))
			{
				return false;
			}
		}
		}
	}
	//printf("return true lien\n");
	return true;
}


