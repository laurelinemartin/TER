#ifndef Contraintes_H
#define Contraintes_H

#include <vector>
#include <iostream>
#include "Eleve.h"
#include "Cours.h"
#include "Salle.h"
using namespace std;

bool contrainte_cours_salle(Salle &p_salle, Cours &p_cours){
    if(p_cours.get_liste_etu().size() > p_salle.get_capacite())
        return false;
    if(p_salle.get_type_salle() != p_cours.get_type_salle())
        return false;
    return true;
}

bool contrainte_professeur_cours(Cours &p_cours){
    if(find(p_cours.get_liste_ens().begin(), p_cours.get_liste_ens().end(), p_cours.get_num_ens()) !=  p_cours.get_liste_ens().end())
        return true;
    return false;
}

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
