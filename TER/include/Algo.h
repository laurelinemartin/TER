#ifndef ALGO_H
#define ALGO_H

#include <vector>
#include <iostream>
#include <algorithm>
#include "Planification.h"
#include "Bus.h"
#include <time.h>
using namespace std;

vector<int> convertHeure(int num);
int *Algo_glouton(int *Horaires, int N, int sommet_depart, int *couleur, int *Type, int **TO, int Nb_iterations, int heure_max, int* Nb_eleves);
int *Algo_tabou_dur(int *Horaires, int N, int sommet_depart, int *couleur, int *Type, int **TO, int Nb_iterations, int heure_max, int* Nb_eleves);

#endif // ALGO_H
