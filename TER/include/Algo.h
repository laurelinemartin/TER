#ifndef Algo_H
#define Algo_H

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int *Algo_glouton(int *Horaires, int N, int sommet_depart, int *couleur, int *Type);
int *Algo_tabou(int *Horaires, int N, int sommet_depart, int *couleur, int *Type, int **T);

int *planification2(int *Horaires, int sommet_depart, int *couleur, int N, int *TYPE, int sommet_fixe, int **T);

#endif // Bus_H