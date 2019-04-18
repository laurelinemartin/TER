#ifndef Bus_H
#define Bus_H

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Bus
{
    public:
        //CTOR/DTOR
        Bus(); //constructeur par défaut
        Bus(int p_heure_arrive, vector<int> p_liste_arret, int p_seuil_confort, int p_capacite_max);
        virtual ~Bus();

        //GETTER
       int get_heure_arrive(){return heure_arrive;}
       int get_seuil_confort(){return seuil_confort;}
       int get_capacite_max(){return capacite_max;}
       vector<int> get_liste_arret(){return liste_arret;}

        //SETTER
       int set_heure_arrive(int p_heure_arrive){heure_arrive = p_heure_arrive;}
       int set_seuil_confort(int p_seuil_confort){seuil_confort = p_seuil_confort;}
       int set_capacite_max(int p_capacite_max){capacite_max = p_capacite_max;}

        //FONCTIONS DE BASE 

    protected:

    private:
        int heure_arrive;
        vector<int> liste_arret;
        int seuil_confort;
        int capacite_max;
};

#endif // Bus_H
