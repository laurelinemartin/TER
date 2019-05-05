#ifndef ALGO_H
#define ALGO_H

#include <vector>
#include <iostream>
#include <algorithm>
#include "Planification.h"
#include "Bus.h"
#include <time.h>
using namespace std;

int *Tri_nb_eleves(int *Nb_eleves);
int *Algo_glouton(int **T, int sommet_depart, int *couleur, int N, int *TYPE, int *Nb_eleves, int heure_max);
int *Algo_tabou(int *Horaires, int N, int sommet_depart, int *couleur, int *Type, int **TO, int Nb_iterations, int heure_max, int Nb_eleves);

int *planification2(int *Horaires, int sommet_depart, int *couleur, int N, int *TYPE, int sommet_fixe, int **T);

#endif // ALGO_H