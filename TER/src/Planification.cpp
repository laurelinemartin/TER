#include "../include/Contraintes.h"
#include "../include/Planification.h"
#include <time.h>

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

//Pour représenter les heures par créneau de 15 min :
//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 : indices
//8       9       10        11          12          14 : heure
int *planification(int **T, int sommet_depart, int *couleur, int N)
{
	int *Horaires = (int*)malloc(N*sizeof(int*));
	Horaires[sommet_depart] = 0;

	for(int i = 0; i < N; i++)
	{
		if(T[i][sommet_depart] == 1)
		{
			//H[i] = 
		}
	}
}