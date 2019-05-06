#include "../include/Bus.h"
#include "../include/Planification.h"
#include <time.h>

int calcul_congestion_bus(int *Nb_eleves_bus, int heure_bus)
{
    int congestion = 0;
    int non_etudiant;
    int seuil_confort = 50;
    srand(time(NULL));

    for(int i = 0; i < 7; i++)
    {
        non_etudiant = montee_descente(heure_bus);

        if((Nb_eleves_bus[heure_bus] + non_etudiant) > seuil_confort)
        {
            congestion++;
        }
    }
    if((Nb_eleves_bus[heure_bus] + non_etudiant) > seuil_confort)
    {
        congestion++;
    }
    if(congestion > 0){
        //printf("congestion du bus %d : %d\n",heure_bus, congestion);
    }
    return congestion;
}

int calcul_congestion_totale(int *Horaires, int *Nb_eleves_cours, int heure_max, int N)
{
    int congestion_totale = 0;
    int capacite_max = 60;

    //mettre une proba de venir d'un autre cours avant
    //Initialisation tableau
    int *Nb_eleves_bus = (int*)malloc(heure_max*sizeof(int*));
    for(int i = 0; i < heure_max; i++){
        Nb_eleves_bus[i] = 0;
    }
    for(int i = 0; i < heure_max; i++){
        Nb_eleves_bus[Horaires[i]-1] += Nb_eleves_cours[i];

        if(Nb_eleves_bus[i] > capacite_max)
        {
            Nb_eleves_bus[i - 1] += Nb_eleves_bus[i] - capacite_max;
            Nb_eleves_bus[i] = capacite_max;
        }
    }

    /*for(int i = 0; i < heure_max; i++){
    printf("Nb eleve bus %d : %d \n ",i ,Nb_eleves_bus[i]); }*/
   

    for(int i = 0; i < heure_max; i++)
    {
        congestion_totale += calcul_congestion_bus(Nb_eleves_bus, i);
    }
    //calculer la mediane ailleur
    return congestion_totale;
}

int montee_descente(int heure_bus)
{
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
    else if (heure_bus <= 34)
    {
        non_etudiant += (rand()%10) + 3; 
        non_etudiant -= (rand()%5) - 1;
    }

    return non_etudiant;
}