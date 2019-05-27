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
}

void ecrireInformation(string s){
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
	// ecrireCongestionBus(bus);
}

void ecrirePlanification(int* horaires, int* salles, int horaireMax){
	int cours = 0;
	vector<int> heure;
  	//// tableau Horaires devient vector<int> vecHoraires
  	vector<int> vecHoraires (horaires, horaires + horaireMax);

  	ofstream fichier("resultats.txt", ios::out | ios::app); 
	if(fichier){
  		for (auto x : vecHoraires) {
  			heure = convertHeure8(x);
  			fichier << "Cours " 
  					<< cours 
  					<< " à " 
  					<< heure[0]
  					<< " h "
  					<< heure[1]
  					<< ", salle : "
  					<< salles[cours]
  					<< endl;
  			cours++;
   		 }
   		 fichier.close();
    }
    else{
    	cerr << "Erreur ouverture !";
    }
}

void ecrireCongestionBus(int* bus, int N){
	vector<int> heure;
	ofstream fichier("congestion_bus.txt", ios::out);
	if(fichier){
		for(int i = 0; i < N; i++){
			heure = convertHeure730(i);
			if(bus[i] < debOrange){
				fichier << "Le bus à l'heure " 
						<< heure[0] 
						<< "h"
						<< heure[1]
						<< " : vert." 
						<< " 1F49A ;	emoji ;	L1 ;	none ;	j "
						<< " (" 
						<< bus[i] 
						<< ")" << endl;
			}
			else if(bus[i] < debRouge){
				fichier << "Le bus à l'heure " 
						<< heure[0] 
						<< "h"
						<< heure[1] 
						<< " : orange." 
						<< " (" 
						<< bus[i] 
						<< ")"  << endl; 
			}
			else{
				fichier << "Le bus à l'heure " 
						<< heure[0] 
						<< "h"
						<< heure[1]
						<< " : rouge." 
						<< " (" 
						<< bus[i] 
						<< ")"  << endl;
			}
		}
		fichier.close();
	}
	else{
		cerr << "Erreur ouverture du fichier !" << endl;
	}
}

void ecrireCongestionTotale(int congestionTotale, int nbbus){
<<<<<<< HEAD
	ofstream fichier("resultats.txt", ios::out | ios::app); 
	if(fichier){
		fichier << "Congestion totale (nombre de bus dans lequel de seuil de confort à été dépassé): "
				<< congestionTotale
=======
	int aff = 0;
	if (congestionTotale%8 == 0)
	{
		aff = congestionTotale/8;
	}
	else
	{
		aff = congestionTotale/8 + 1;
	}
	// FILE *sortie = fopen("resultats.txt", "a");
	// fprintf(sortie, "Congestion totale (nombre de bus dans lequel de seuil de confort à été dépassé): %d / %d", congestionTotale, nbbus);
	// fclose(sortie);
	ofstream fichier("resultats.txt", ios::out | ios::app); 
	if(fichier){
		fichier << "Congestion totale (nombre de bus dans lequel de seuil de confort à été dépassé): "
				<< aff
>>>>>>> 1b68c9d7f7be5688ae70f64f68800bbcb4c0b28a
				<< " / "
				<< nbbus
				<< endl;
		fichier.close();
	}
	else{
		cerr << "Erreur ouverture !";
	}
}


////////////////////////////////////////////////////////////////////

float lectureProbabilite(){
	float proba;
	ifstream fichier("params.txt", ios::in);
	if(fichier){
		fichier >> proba;
		fichier.close();
	}
	else{
		cerr << "Erreur lecture params.txt !";
	}
	return proba;
}

int lectureNombreCours(){
	int nombreCours;
	string saut;
	ifstream fichier("params.txt", ios::in);
	if(fichier){
		for(int i = 0; i < 1; i++){
			getline(fichier, saut);
		}
		fichier >> nombreCours;
		fichier.close();
	}
	else{
		cerr << "Erreur lecture params.txt !";
	}
	return nombreCours;
}

int lectureNombreSalles(){
	int nombreSalles;
	string saut;
	ifstream fichier("params.txt", ios::in);
	if(fichier){
		for(int i = 0; i < 2; i++){
			getline(fichier, saut);
		}
		fichier >> nombreSalles;
		fichier.close();
	}
	else{
		cerr << "Erreur lecture params.txt !";
	}
	return nombreSalles;
}

int lectureNombreBus(){
	int nombreBus;
	string saut;
	ifstream fichier("params.txt", ios::in);
	if(fichier){
		for(int i = 0; i < 3; i++){
			getline(fichier, saut);
		}
		fichier >> nombreBus;
		fichier.close();
	}
	else{
		cerr << "Erreur lecture params.txt !";
	}
	return nombreBus;
}

int lectureNombreIterations(){
	int nombreIterations;
	string saut;
	ifstream fichier("params.txt", ios::in);
	if(fichier){
		for(int i = 0; i < 4; i++){
			getline(fichier, saut);
		}
		fichier >> nombreIterations;
		fichier.close();
	}
	else{
		cerr << "Erreur lecture params.txt !";
	}
	return nombreIterations;
}