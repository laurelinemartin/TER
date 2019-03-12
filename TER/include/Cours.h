#ifndef Cours_H
#define Cours_H

#include <vector>
#include <iostream>
#include "Eleve.h"
using namespace std;

typedef struct horaire{
	int heure;
	int minute;
}HORAIRE;

class Cours
{
    public:
        //CTOR/DTOR
        Cours();
        virtual ~Cours();

        //GETTER
        int get_duree() { return duree; }
        int get_SalleType() { return SalleType; }
        int get_SalleId() { return SalleId; }
        int get_ProfId() { return ProfId; }
        int get_nbEleve() { return nbEleve;}
        int get_flexibilite() { return flexibilite;}
        HORAIRE get_heuredebut() { return heuredebut;}
        HORAIRE get_heurefin() { return heurefin;}

        //SETTER
        void set_duree(int val) { duree = val; }
        void set_SalleType(int val) { SalleType = val; }
        void set_SalleId(int val) { SalleId = val; }
        void set_ProfId(int val) { ProfId = val; }
        void set_flexibilite(int val) { flexibilite = val; }

        //TEST
        void addEleve(Eleve eleve);
        void description();
        void modificationHoraireDebut (int heure, int minute);
        void modificationHoraireFin (int heure, int minute);

    protected:

    private:
        int duree;
        int SalleType;
        int SalleId;
        int ProfId;
        int ListEleve[nbEleve];
        int nbEleve;
        int flexibilite;
        HORAIRE heuredebut;
        HORAIRE heurefin;
};

#endif // Cours_H
