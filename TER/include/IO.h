#ifndef IO_H
#define IO_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//// Variables golables /////
#define nbResults 10

void initFichier();
void ecrireSolution();
void ecrireSolution();
void ecrirePlanification();
void ecrireCongestionBus(int numBus, int congestionBus);
void ecrireCongestionTotale(int congestionTotale);

#endif //IO_H
