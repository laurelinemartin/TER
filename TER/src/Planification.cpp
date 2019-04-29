#include "../include/Contraintes.h"
#include "../include/Planification.h"
#include <time.h>

int **matrice_adjacence (int N, float K)
{
	int **T = (int**)malloc(N*sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		T[i] = (int*) malloc(N*sizeof(int));
	}
	int x = 0;
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			x = rand()%100;
			if (x <= (K*100))
			{
				T[i][j] = 1;
			}
			else
			{
				T[i][j] = 0;
			}
		}
	}
	return T;
}

//pas besoin de fonction pour orienter le graphe suffis de lire la matrice d'adjacence en escalier c'est facile

int *coloration (int N, int Nb)
{
	int *T = (int*)malloc(N*sizeof(int*));
	int couleur = 0;
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		couleur = rand()%(Nb);
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
	return NULL;
}