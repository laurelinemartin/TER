#ifndef IO_H
#define IO_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;

//// Variables golables ////
#define nbResults 10
#define lapseHeure 15

void initFichier();
void ecrireSolution();
void ecrireSolution();
void ecrirePlanification(int* horaires, int tailleTab);
void ecrireCongestionBus(int numBus, int congestionBus);
void ecrireCongestionTotale(int congestionTotale);

#endif //IO_H
