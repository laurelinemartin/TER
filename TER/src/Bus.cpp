#include "../include/Bus.h"

//Calcul la congestion de un bus à une horaire donné
int calcul_congestion_bus(int *Nb_eleves_bus, int heure_bus){
    int congestion = 0;
    int non_etudiant = 0;
    int seuil_confort = 50;
    int oui_ou_non = 0;
    //  Il y a 8 arrêts
    for(int i = 0; i < 7; i++){
        non_etudiant = montee_descente(heure_bus);
        if((Nb_eleves_bus[heure_bus] + non_etudiant) > seuil_confort){
            congestion++;
        }
    }
    if((Nb_eleves_bus[heure_bus] + non_etudiant) > seuil_confort){
        congestion++;
    }

    if(congestion > 0) { congestion = 1;}

    return congestion;
}

int* congestionBus(int heure_max, int N, int *Horaires, int *Nb_eleves_cours){

    int capacite_max = 60;
    int *Nb_eleves_bus = (int*)malloc(heure_max*3*sizeof(int*));
    for(int i = 0; i < heure_max*3; i++){
        Nb_eleves_bus[i] = 0;
    }

    for(int i = 0; i < N; i++){
        Nb_eleves_bus[Horaires[i]-1] += Nb_eleves_cours[i];
    }

    for (int j = 0; j < 2; j++){
        for(int i = 1; i < heure_max*3; i++){
            if(Nb_eleves_bus[i] > capacite_max){
                Nb_eleves_bus[i - 1] += Nb_eleves_bus[i] - capacite_max;
                Nb_eleves_bus[i] = capacite_max;
            }
        }
    }

    for(int i = 0; i < heure_max; i++){
    printf("Nb eleve bus %d : %d \n ",i ,Nb_eleves_bus[i]); }
    return Nb_eleves_bus;
}

//Calcule le nombre d'élèves dans chaque bus
int* nbElevesBus(int* Horaires, int* Nb_eleves_cours, int heure_max, int N){
    int capacite_max = 60;
    int *Nb_eleves_bus = (int*)malloc(heure_max*3*sizeof(int*));
    for(int i = 0; i < heure_max*3; i++){
        Nb_eleves_bus[i] = 0;
    }
    for(int i = 0; i < N; i++){
        Nb_eleves_bus[Horaires[i]-1] += Nb_eleves_cours[i];
    }
    for (int j = 0; j < 2; j++){
        for(int i = 1; i < heure_max*3; i++){
            if(Nb_eleves_bus[i] > capacite_max){
                Nb_eleves_bus[i - 1] += Nb_eleves_bus[i] - capacite_max;
                Nb_eleves_bus[i] = capacite_max;
            }
        }
    }
    return Nb_eleves_bus;    
}

//Calcul le nombre de bus congestioné pour une planification donné
int calcul_congestion_totale(int *Horaires, int *Nb_eleves_cours, int heure_max, int N, int **T){
    int congestion_totale = 0;
    int capacite_max = 60;
    //variable utilisé pour répartir les élèves d'un cours père dans les cours fils
    int eleves_restant = 0;

    int *Nb_eleves_bus = (int*)malloc(heure_max*3*sizeof(int*));
    for(int i = 0; i < heure_max*3; i++){
        Nb_eleves_bus[i] = 0;
    }

        //Prise en compte des élèves déjà à l'université  
        for(int i = 0; i < N; i++)
        {
            eleves_restant = Nb_eleves_cours[i];
            for(int k = 0; k < N; k++)
            {
                if((T[k][i] == 1) && (eleves_restant >= 1)	&& (Horaires [k] > Horaires[i]))
                {
                    if(Nb_eleves_bus[Horaires[k]-1] <= eleves_restant)
                    {
						eleves_restant -= Nb_eleves_bus[Horaires[k]-1];
                        Nb_eleves_bus[Horaires[k]-1] = 0;
                    }
                    else
                    {
                        Nb_eleves_bus[Horaires[k]-1] -= eleves_restant;
                        eleves_restant = 0;
                    }       
                }
            }
        }
  
    Nb_eleves_bus = nbElevesBus(Horaires, Nb_eleves_cours, heure_max, N);  
    for(int i = 0; i < heure_max; i++)
    {
        congestion_totale += calcul_congestion_bus(Nb_eleves_bus, i);
    }
    return congestion_totale;
}

//Permet de rentrer les valeurs de montée et descente à chaque arrêt des non-etudiants
int montee_descente(int heure_bus)
{
    srand(time(NULL));
    int non_etudiant = 0;
    if (heure_bus <= 6)
    {
        non_etudiant += (rand()%10) + 5; 
        non_etudiant -= (rand()%5); 
    }
    else if (heure_bus <= 10)
    {
        non_etudiant += (rand()%10) + 3; 
        non_etudiant -= (rand()%6) + 1;
    }
    else if (heure_bus <= 14)
    {
        non_etudiant += (rand()%8) + 2; 
        non_etudiant -= (rand()%6) + 1;
    }
    else if (heure_bus <= 22)
    {
        non_etudiant += (rand()%5) + 1; 
        non_etudiant -= (rand()%5) + 1;
    }
    else if (heure_bus <= 26)
    {
        non_etudiant += (rand()%5) + 1; 
        non_etudiant -= (rand()%5);
    }
    else if (heure_bus <= 30)
    {
        non_etudiant += (rand()%8) + 2; 
        non_etudiant -= (rand()%5);
    }
    else
    {
        non_etudiant += (rand()%10) + 3; 
        non_etudiant -= (rand()%5) - 1;
    }

    return non_etudiant;
}
