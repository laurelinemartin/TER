#include "../include/IO.h"
using namespace std;

//// Variables golables /////
#define nbResults 10

void initFichier(){
	FILE *sortie = fopen("resultats.txt", "w");
	fprintf(sortie, "Les %d meilleurs résultats : \n", nbResults);
	fclose(sortie);
}