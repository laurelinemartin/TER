#ifndef Contraintes_H
#define Contraintes_H

#include <vector>
#include <iostream>
#include "Eleve.h"
using namespace std;

typedef struct horaire{
	int heure;
	int minute;
}HORAIRE;

class Contraintes
{
    public:

        Contraintes();
        virtual ~Contraintes();

        //GETTER
        int get_identifiant() { return identifiant; }
        //int* get_etudiantscontrainte() {return etudiantscontrainte; }

        //SETTER
        void set_identifiant(int val) { duree = val; }

    private:
        int identifiant;
        vector<int> etu_contraintes(int nbetu);
};

#endif // Contraintes_H
