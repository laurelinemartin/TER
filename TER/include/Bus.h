#ifndef Bus_H
#define Bus_H

#include <vector>
#include <iostream>
#include <algorithm>
#include "Planification.h"
#include "IO.h"
#include <time.h>
using namespace std;

int calcul_congestion_bus(int *Nb_eleves_bus, int heure_bus);
int* congestionBus(int* Nb_eleves, int N);
int calcul_congestion_totale(int *Horaires, int *Nb_eleves_cours, int heure_max, int N, int **T);
int montee_descente(int heure_bus);

#endif // Bus_H
