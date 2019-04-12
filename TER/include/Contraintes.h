#ifndef Contraintes_H
#define Contraintes_H

#include <vector>
#include <iostream>
#include "Etudiant.h"
#include "Cours.h"
#include "Salle.h"
using namespace std;

bool contrainte_cours_salle(Salle &p_salle, Cours &p_cours);

bool contrainte_professeur_cours(Cours &p_cours);

bool contrainte_cours_cours(Cours &p_cours1, Cours &p_cours2);


/*typedef struct horaire{
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
};*/

#endif // Contraintes_H
