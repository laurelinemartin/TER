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

int **matrice_adjacence_GNO (int N, float K);
int *coloration (int N, int Nb);
int trouver_degre_entrant_nul (int **T, int N);
int **matrice_graphe_oriente (int **T, int N);
int *nb_eleves (int *TYPE, int N);
int *type_cours (int N);
bool test_coloration(int *Horaires, int *couleur, int N, int *TYPE, int heure_a_teste, int sommet_a_teste);
int *planification(int **T, int sommet_depart, int *couleur, int N, int *TYPE);


#endif // Planification_H
