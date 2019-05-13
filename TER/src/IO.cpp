#include "../include/IO.h"
using namespace std;

void initFichier(){
	ofstream fichier("resultats.txt", ios::out); 
	if(fichier){
		fichier << "Les meilleurs résultats : " << endl;
		fichier.close();
	}
	else{
		cerr << "Erreur ouverture fichier !" << endl;
	}
	// FILE *sortie = fopen("resultats.txt", "w");
	// fprintf(sortie, "Les %d meilleurs résultats : \n\n", nbResults);
	// fclose(sortie);
}

void ecrireInformation(char* s){
	ofstream fichier("resultats.txt", ios::out | ios::app);
	if(fichier){
		fichier << s << endl;
	}
	else{
		cerr << "Erreur ouverture !";
	}
}

void ecrireSolution(int* horaires, int* salles, int horaireMax, int nbBus, int congestionTotale){
	ecrirePlanification(horaires, salles, horaireMax);
	ecrireCongestionTotale(congestionTotale, nbBus);
}

void ecrirePlanification(int* horaires, int* salles, int horaireMax){
	// FILE *sortie = fopen("resultats.txt", "a");
	int cours = 0;
	vector<int> heure;
  	//// tableau Horaires devient vector<int> vecHoraires
  	vector<int> vecHoraires (horaires, horaires + horaireMax);
  	//// tri de vecHoraire
  	//// sort(vecHoraires.begin(), vecHoraires.end());
  	// fprintf(sortie, "\nPLANIFICATION DES COURS :\n");

  	ofstream fichier("resultats.txt", ios::out | ios::app); 
	if(fichier){
  		for (auto x : vecHoraires) {
  			heure = convertHeure(x);
  			fichier << "Cours " 
  					<< cours 
  					<< " à " 
  					<< heure[0]
  					<< " h "
  					<< heure[1]
  					<< ", salle : "
  					<< salles[cours]
  					<< endl;
  			// fprintf(sortie, "Cours %d à %d h %d salle : %d\n", cours, heure[0], heure[1], salles[cours]);
  			cours++;
   		 }
   		 fichier.close();
    }
    else{
    	cerr << "Erreur ouverture !";
    }
    // fclose(sortie);
}

void ecrireCongestionBus(int numBus, int congestionBus){
	FILE *sortie = fopen("resultats.txt", "a");
	// fprintf(sortie, "CONGESTION DES BUS : \n");
	fprintf(sortie, "-------------------------\n");
	fprintf(sortie, "Congestion du bus n°%d : %d\n", numBus, congestionBus);
	fclose(sortie);
}

void ecrireCongestionTotale(int congestionTotale, int nbbus){
	// FILE *sortie = fopen("resultats.txt", "a");
	// fprintf(sortie, "Congestion totale (nombre de bus dans lequel de seuil de confort à été dépassé): %d / %d", congestionTotale, nbbus);
	// fclose(sortie);
	ofstream fichier("resultats.txt", ios::out | ios::app); 
	if(fichier){
		fichier << "Congestion totale (nombre de bus dans lequel de seuil de confort à été dépassé): "
				<< congestionTotale/8
				<< " / "
				<< nbbus
				<< endl;
		fichier.close();
	}
	else{
		cerr << "Erreur ouverture !";
	}
}