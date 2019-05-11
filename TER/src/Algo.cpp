#include "../include/Algo.h"


//// récupère un int qui correspond au nombre représentant
//// l'heure dans la table Horaires.
//// Considère que 2 = 8h00
//// à chaque tour de boucle, min augmente du temps défini (ici une variable
//// globale lapseHeure = 15)
//// mets l'heure et les minutes dans un vecteur et le retourne
vector<int> convertHeure(int num){
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


int *Algo_glouton(int *Horaires, int N, int sommet_depart, int *couleur, int *Type, int **TO, int Nb_iterations, int heure_max, int* Nb_eleves)
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
	
	//printf("Le sommet modifie est le : %d\n", sommet_modifie);
	for(int i = 0; i < N; i++)
	{
		sommet_modifie = i;
		horaire_initiale = Horaires_tabou_dur[sommet_modifie];
		while(j < heure_max - 1)
		{
			Horaires_tabou_dur[sommet_modifie] = j;
			if (test_solution_valide(Horaires_tabou_dur, N, couleur, Type, TO) == true)
			{
				printf("Solution valide avec %d à l'heure : %d\n",sommet_modifie,Horaires_tabou_dur[sommet_modifie]);
				temp = calcul_congestion_totale(Horaires_tabou_dur,Nb_eleves,heure_max,N,TO);
				printf("Sa congestion est : %d\n",temp);
				if(temp < meilleure_congestion)
				{
					meilleur_sommet = i;
					meilleure_solution = Horaires_tabou_dur[i];
					meilleure_congestion = temp;
					printf("Meilleure solution sommet %d à l'heure %d de congestion %d\n",i,meilleure_solution,meilleure_congestion);
				}
				//print dans le fichier de sortie
			}
			j++;
		}
		j = 2;
		Horaires_tabou_dur[sommet_modifie] = horaire_initiale;
		//printf("L'horaires choisis pour %d est : %d\n",sommet_modifie,Horaires[sommet_modifie]);
		//fixer a la meilleure solution valide la aussi
	}
	Horaires_tabou_dur[meilleur_sommet] = meilleure_solution;
	printf("Le sommet modifié au final est %d à l'horaire : %d",meilleur_sommet,Horaires_tabou_dur[meilleur_sommet]);
	return Horaires_tabou_dur;
}
