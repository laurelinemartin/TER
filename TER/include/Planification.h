#ifndef Planification_H
#define Planification_H

#include <vector>
#include <iostream>
#include "Etudiant.h"
#include "Cours.h"
#include "Salle.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h

using namespace std;

int **matrice_adjacence (int N, float K);
int *coloration (int N, int Nb);
int trouver_degre_entrant_nul (int **T, int N);


#endif // Planification_H
