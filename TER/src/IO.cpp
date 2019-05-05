#include "../include/IO.h"
using namespace std;

void initFichier(){
	FILE *sortie = fopen("resultats.txt", "w");
	fprintf(sortie, "Les %d meilleurs résultats : \n\n", nbResults);
	fclose(sortie);
}

void ecrireSolution(){
	ecrirePlanification();
	ecrireCongestionBus(0, 0);
	ecrireCongestionTotale(0);
}

void ecrirePlanification(){

}

void ecrireCongestionBus(int numBus, int congestionBus){
	FILE *sortie = fopen("resultats.txt", "w");
	fprintf(sortie, "CONGESTION DES BUS : \n");
	fprintf(sortie, "-------------------------\n");
	fprintf(sortie, "Congestion du bus n°%d : %d\n", numBus, congestionBus);
	fclose(sortie);
}

void ecrireCongestionTotale(int congestionTotale){
	FILE *sortie = fopen("resultats.txt", "a");
	printf("Apres ouverture\n");
	fprintf(sortie, "Congestion totale : %d", congestionTotale);
	printf("Apres ecriture fichier\n");
	fclose(sortie);
}