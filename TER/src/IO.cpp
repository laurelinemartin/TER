#include "../include/IO.h"
using namespace std;

void initFichier(){
	FILE *sortie = fopen("resultats.txt", "w");
	fprintf(sortie, "Les %d meilleurs résultats : \n\n", nbResults);
	fclose(sortie);
}

void ecrireSolution(){
//	int* tab[1];
//	ecrirePlanification(tab, 0);
	ecrireCongestionBus(0, 0);
	ecrireCongestionTotale(0);
}

void ecrirePlanification(int* horaires, int horaireMax){
  	vector<int> myvector (horaires, horaires + horaireMax);
}

void ecrireCongestionBus(int numBus, int congestionBus){
	FILE *sortie = fopen("resultats.txt", "a");
	// fprintf(sortie, "CONGESTION DES BUS : \n");
	fprintf(sortie, "-------------------------\n");
	fprintf(sortie, "Congestion du bus n°%d : %d\n", numBus, congestionBus);
	fclose(sortie);
}

void ecrireCongestionTotale(int congestionTotale){
	FILE *sortie = fopen("resultats.txt", "a");
	fprintf(sortie, "Congestion totale : %d", congestionTotale);
	fclose(sortie);
}