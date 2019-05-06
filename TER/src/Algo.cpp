#include "../include/Algo.h"

int *Algo_tabou(int *Horaires, int N, int sommet_depart, int *couleur, int *Type, int **TO, int Nb_iterations, int heure_max, int* Nb_eleves)
{
	int meilleure_solution;
	int meilleure_congestion;
	int temp = 0;
	int j = 2;
	int sommet_modifie;
	for (int i = 0; i < N; i++)
	{
		sommet_modifie = i;
		meilleure_solution = Horaires[sommet_modifie];
		meilleure_congestion = calcul_congestion_totale(Horaires,Nb_eleves,heure_max,N);
		printf("Le sommet modifie est le : %d\n", sommet_modifie);
		while(j < heure_max - 1)
		{
			Horaires[sommet_modifie] = j;
			if (test_solution_valide(Horaires, N, couleur, Type, TO) == true)
			{
				//printf("Solution valide avec %d à l'heure : %d\n",sommet_modifie,Horaires[sommet_modifie]);
				temp = calcul_congestion_totale(Horaires,Nb_eleves,heure_max,N);
				//printf("Sa congestion est : %d\n",temp);
				if(temp < meilleure_congestion)
				{
					meilleure_solution = Horaires[sommet_modifie];
					meilleure_congestion = temp;
				}
				
				//print dans le fichier de sortie
				//reagreder derriere aussi
			}
			j++;
		}
		j = 2;
		Horaires[sommet_modifie] = meilleure_solution;
		printf("L'horaires choisis pour %d est : %d\n",sommet_modifie,Horaires[sommet_modifie]);
		//fixer a la meilleure solution valide la aussi
	}
	return Horaires;	
}
