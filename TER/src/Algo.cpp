#include "../include/Algo.h"


//// récupère un int qui correspond au nombre représentant
//// l'heure dans la table Horaires.
//// Considère que 2 = 8h00
//// à chaque tour de boucle, min augmente du temps défini (ici une variable
//// globale lapseHeure = 15)
//// mets l'heure et les minutes dans un vecteur et le retourne
vector<int> convertHeure730(int num){
	int heure = 7;
	int min = 30;
	vector<int> vecHeure;
	for(int i = 2; i != num; i++){
		min += lapseHeure;
		if(min % 60 == 0){
			heure++;
			min = 0;
		}
	}
	vecHeure.push_back(heure);
	vecHeure.push_back(min);
	return vecHeure;
}

vector<int> convertHeure8(int num){
	int heure = 8;
	int min = 0;
	vector<int> vecHeure;
	for(int i = 2; i != num; i++){
		min += lapseHeure;
		if(min % 60 == 0){
			heure++;
			min = 0;
		}
	}
	vecHeure.push_back(heure);
	vecHeure.push_back(min);
	return vecHeure;
}


int *Algo_glouton(int *Horaires, int N, int sommet_depart, int *couleur, int *Type, int **TO, int heure_max, int* Nb_eleves)
{
	int *Horaires_glouton = (int*)malloc(N*sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		Horaires_glouton[i] = Horaires[i];
	}
	
	int meilleure_solution;
	int meilleure_congestion;
	int temp = 0;
	int j = 2;
	int sommet_modifie;
	for (int i = 0; i < N; i++)
	{
		sommet_modifie = i;
		meilleure_solution = Horaires_glouton[sommet_modifie];
		meilleure_congestion = calcul_congestion_totale(Horaires_glouton,Nb_eleves,heure_max,N,TO);
		//printf("Le sommet modifie est le : %d\n", sommet_modifie);
		while(j < heure_max - 1)
		{
			Horaires_glouton[sommet_modifie] = j;
			if (test_solution_valide(Horaires_glouton, N, couleur, Type, TO) == true)
			{
				//printf("Solution valide avec %d à l'heure : %d\n",sommet_modifie,Horaires[sommet_modifie]);
				temp = calcul_congestion_totale(Horaires_glouton,Nb_eleves,heure_max,N,TO);
				//printf("Sa congestion est : %d\n",temp);
				if(temp < meilleure_congestion)
				{
					meilleure_solution = Horaires_glouton[sommet_modifie];
					meilleure_congestion = temp;
				}
				
				//print dans le fichier de sortie
				//reagreder derriere aussi
			}
			j++;
		}
		j = 2;
		Horaires_glouton[sommet_modifie] = meilleure_solution;
		//printf("L'horaires choisis pour %d est : %d\n",sommet_modifie,Horaires_glouton[sommet_modifie]);
		//fixer a la meilleure solution valide la aussi
	}
	return Horaires_glouton;	
}

int *Algo_tabou_dur(int *Horaires, int N, int sommet_depart, int *couleur, int *Type, int **TO, int Nb_iterations, int heure_max, int* Nb_eleves)
{
	int *Horaires_tabou_dur = (int*)malloc(N*sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		Horaires_tabou_dur[i] = Horaires[i];
	}

	int *Sommets_interdits = (int*)malloc(Nb_iterations*sizeof(int*));
	for (int i = 0; i < Nb_iterations; i++)
	{
		Sommets_interdits[i] = 1000;
	}
	
	int meilleure_solution;
	int meilleure_congestion;
	int meilleur_sommet = 0;
	int temp = 0;
	int horaire_initiale;
	int j = 2;
	int sommet_modifie;
	
	//Initialisation au sommet 0
	sommet_modifie = 0;
	meilleure_solution = Horaires_tabou_dur[sommet_modifie];
	meilleure_congestion = calcul_congestion_totale(Horaires_tabou_dur,Nb_eleves,heure_max,N,TO);
	
	for(int k = 0; k < Nb_iterations; k++){
		for(int i = 0; i < N; i++){
			for(int l = 0; l < k; l++){
				if(i == Sommets_interdits[l]){
					i++;
					l = 0;
				}
			}
			sommet_modifie = i;
			horaire_initiale = Horaires_tabou_dur[sommet_modifie];
			while(j < heure_max - 1){
				Horaires_tabou_dur[sommet_modifie] = j;
				if (test_solution_valide(Horaires_tabou_dur, N, couleur, Type, TO) == true){
					temp = calcul_congestion_totale(Horaires_tabou_dur,Nb_eleves,heure_max,N,TO);
					if(temp < meilleure_congestion){
						meilleur_sommet = i;
						meilleure_solution = Horaires_tabou_dur[i];
						meilleure_congestion = temp;
					}
				}
				j++;
			}
			j = 2;
			Horaires_tabou_dur[sommet_modifie] = horaire_initiale;
			//fixer a la meilleure solution valide la aussi
		}
		Horaires_tabou_dur[meilleur_sommet] = meilleure_solution;
		printf("Le sommet modifié au final est %d à l'horaire : %d\n",meilleur_sommet,Horaires_tabou_dur[meilleur_sommet]);
		Sommets_interdits[k] = meilleur_sommet;
	}
	free(Sommets_interdits);
	return Horaires_tabou_dur;
}

int *Algo_tabou_roulette(int *Horaires, int N, int sommet_depart, int *couleur, int *Type, int **TO, int Nb_iterations, int heure_max, int* Nb_eleves)
{
	//Declaration d'un nouveau tableau pour ne pas ecraser le tableau contenant la planification initiale
	int *Horaires_tabou_roulette = (int*)malloc(N*sizeof(int*));
	for (int i = 0; i < N; i++){
		Horaires_tabou_roulette[i] = Horaires[i];
	}

	//Tableau qui servira à vérifier si un sommet a déjà été modifié et ainsi l'interdire
	int *Sommets_interdits = (int*)malloc(Nb_iterations*sizeof(int*));
	for (int i = 0; i < Nb_iterations; i++){
		Sommets_interdits[i] = 1000;
	}

	//Tableau contenant la meilleure horaire pour un sommet donné
	int *Meilleure_solution = (int*)malloc(N*sizeof(int*));
	for (int i = 0; i < N; i++){
		Meilleure_solution[i] = 0;
	}

	//Tableau contenant la meilleure solution pour un sommet donné
	int *Meilleure_congestion = (int*)malloc(N*sizeof(int*));
	for (int i = 0; i < N; i++){
		Meilleure_congestion[i] = 0;
	}

	//Tableau contenant les probabilité qu'un sommet sois choisis par la roulette
	int *Valeurs_roulette = (int*)malloc(N*sizeof(int*));

	//i=Initialisation
	int congestion_initiale = 0;
	srand(time(NULL));
	int temp = 0;
	int choix_roulette = 0;
	int horaire_initiale = 0;;
	int j = 2;
	
	//La boucle k permet d'itérer l'algo plusieurs fois
	for(int k = 0; k < Nb_iterations; k++){
		temp = 0;
		choix_roulette = 0;
		horaire_initiale = 0;
		//On reinitialise les probas
		for (int o = 0; o < N; o++){
			Valeurs_roulette[o] = 0;
			Meilleure_congestion[o] = 0;
			Meilleure_solution[o] = 0;
		}
		congestion_initiale = calcul_congestion_totale(Horaires_tabou_roulette,Nb_eleves,heure_max,N,TO);
		printf("Congestion initiale à l'itération %d : %d\n",k,congestion_initiale);

		//La boucle i parcoure l'ensemble des sommets
		for(int i = 0; i < N; i++){
			//On cherche a savoir si le sommet courant est un sommet déjà modifié, si oui on ne le regarde pas
			for(int l = 0; l < k+1; l++){
				if(i == Sommets_interdits[l]) {i++; l = 0;}
			}
			//Initialisation des meilleures solution pour le sommet i
			Meilleure_solution[i] = Horaires_tabou_roulette[i];
			Meilleure_congestion[i] = calcul_congestion_totale(Horaires_tabou_roulette,Nb_eleves,heure_max,N,TO);
			horaire_initiale = Horaires_tabou_roulette[i];

			//La boucle j parcours l'ensemble des horaires possibles
			while(j < heure_max - 1){
				Horaires_tabou_roulette[i] = j;
				//On verifie que l'horaire est bien valide
				if (test_solution_valide(Horaires_tabou_roulette, N, couleur, Type, TO) == true){
					temp = calcul_congestion_totale(Horaires_tabou_roulette,Nb_eleves,heure_max,N,TO);
					//Si la congestion de cette horaire est meilleure, on met à jour le meilleur horaire et la meilleur congestion du sommet i
					if(temp < Meilleure_congestion[i]){
						Meilleure_congestion[i] = temp;
						Meilleure_solution[i] = j;
						printf("Meilleure solution sommet %d à l'heure %d de congestion %d\n",i,Meilleure_solution[i],Meilleure_congestion[i]);
					}
				}
				j++;
			}
			//j commence à 2 car 2 correspond à 8h du matin, l'horaire minimale
			j = 2;
			//On remet l'horaire du sommet i a son horaire de base car on sait pas encore quel sommet sera modifié à cette itération de l'algo tabou
			Horaires_tabou_roulette[i] = horaire_initiale;
			//On remplit le tableau des proba de cette manière :
			//On marque la valeurs de modification par rapport a la congestion initiale. Ainsi si on a 10 de congestion initiale et 8 en congestion pour le sommet i,
			//Alors on marque 2 dans le tableau. Pour le sommet suivant si il modifie de 3 on marque 5. Ainsi ca donne un tableau comme cela : 
			//2 4 8 15 16 17 17.
			if(Meilleure_congestion[i] < congestion_initiale){ Valeurs_roulette[i] = congestion_initiale - Meilleure_congestion[i]; }
			else { Valeurs_roulette[i] = 0; }
		}
		for (int p = 1; p < N; p++) { 
			if (Valeurs_roulette[p] == 0) { Valeurs_roulette[p] = Valeurs_roulette[p-1];} 
			else { Valeurs_roulette[p] += Valeurs_roulette[p-1]; }
		}

		printf("Valeurs roulette\n");
		for (int n = 0; n < N; n++) {
			printf("%d ",Valeurs_roulette[n]);
		}
		printf("\n");
		
		if (Valeurs_roulette[N-1] > 0) {
			choix_roulette = rand()%Valeurs_roulette[N-1];
		}
		else { choix_roulette = 0; }
		
		printf("Choix roulette : %d\n",choix_roulette);

		//On prend au hasard une valeur et on regarde ou elle tombe dans le tableau, ainsi plus on modifie la congestion, plus on a de chance d'être choisi.
		if ((choix_roulette > 0) && (choix_roulette <= Valeurs_roulette[0])){
			Horaires_tabou_roulette[0] = Meilleure_solution[0];
			Sommets_interdits[k] = 0;
			printf("Le sommet modifié au final dans l'lgo roulette est %d à l'horaire : %d\n", 0, Horaires_tabou_roulette[0]);
		}
		else{
			for (int m = 1; m < N; m++){
				if ((choix_roulette >= Valeurs_roulette[m-1]) && (choix_roulette <= Valeurs_roulette[m])){
					//Mise a jour de la planification et des sommets interdits
					Horaires_tabou_roulette[m] = Meilleure_solution[m];
					printf("Le sommet modifié au final dans l'algo roulette est %d à l'horaire : %d\n",m,Horaires_tabou_roulette[m]);
					Sommets_interdits[k] = m;
					m = N;
				}
			}
		}
	}	
	//Libération de la mémoire et return
	free(Sommets_interdits);
	free(Meilleure_solution);
	free(Meilleure_congestion);
	free(Valeurs_roulette);
	printf("fin algo roulette\n");
	return Horaires_tabou_roulette;
}
