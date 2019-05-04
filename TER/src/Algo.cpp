#include "../include/Algo.h"
#include "../include/Planification.h"
#include "../include/Bus.h"
#include <time.h>

int *Tri_nb_eleves(int *Nb_eleves)
{
	int min = Nb_eleves[0];
	int Tab_triee[N];
	Tab_triee[0] = 0;
	for (int i = 1; i < N; i++)
	{
		temp = Nb_eleves[i];
		if(min > temp)
		{
			
		}
	}
}

int *Algo_glouton(int **T, int sommet_depart, int *couleur, int N, int *TYPE, int *Nb_eleves)
{
	int *Horaires = (int*)malloc(N*sizeof(int*));
	Horaires[sommet_depart] = 0;

	for(int i = 1; i < N; i++)
	{

	}
}

int *Algo_tabou(int *Horaires, int N, int sommet_depart, int *couleur, int *Type, int **T, int Nb_iterations)
{
	srand(time(NULL));
	
		int sommet_modifie = rand()%N;
		printf("Le sommet modifie est le : %d\n", sommet_modifie);

		Horaires[sommet_modifie] += 4;
		return planification2(Horaires, sommet_depart, couleur, N, Type, sommet_modifie, T);
	
	
}

int *planification2(int *Horaires, int sommet_depart, int *couleur, int N, int *TYPE, int sommet_fixe, int **T)
{
	for(int i = 0; i < N; i++)
	{
		if(i != sommet_fixe)
		{
			Horaires[i] = 0;
		}
	}

	for(int i = 1; i < N; i++)
	{
		if(i != sommet_fixe)
		{
		for(int k = 0; k < N; k++)
		{
			if(T[i][k] == 1)
			{
				if(TYPE[i] == 0)//si le cours est un td
				{
					for(int j = 0; j < 35; j++)
					{
						if(test_coloration(Horaires, couleur, N, TYPE, Horaires[k] + 13 + j, i) == true)
						{
							if(test_lien(Horaires, N, T, Horaires[k] + 13 + j, i) == true)
							{
								Horaires[i] = Horaires[k] + 13 + j;
								break;
							}
						}
					}

				}
				else //si le cours est un cm
				{
					for(int j = 0; j < 35; j++)
					{
						if(test_coloration(Horaires, couleur, N, TYPE, Horaires[k] + 7 + j,i) == true)
						{
							if(test_lien(Horaires, N, T, Horaires[k] + 7 + j, i) == true)
							{
								Horaires[i] = Horaires[k] + 7 + j;
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
						for(int j = 0; j < 35; j++)
						{
							if(test_coloration(Horaires, couleur, N, TYPE, Horaires[k] + 13 + j, i) == true)
							{
								if(test_lien(Horaires, N, T, Horaires[k] + 13 + j, i) == true)
								{
									Horaires[i] = Horaires[k] + 13 + j;
									break;
								}
							}
						}
					}
					else //si le cours est un cm
					{
						for(int j = 0; j < 35; j++)
						{
							if(test_coloration(Horaires, couleur, N, TYPE, Horaires[k] + 7 + j,i) == true)
							{
								if(test_lien(Horaires, N, T, Horaires[k] + 7 + j, i) == true)
								{
									Horaires[i] = Horaires[k] + 7 + j;
									break;
								}
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
