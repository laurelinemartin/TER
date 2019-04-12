#ifndef Contraintes_H
#define Contraintes_H

#include <vector>
#include <iostream>
#include "Etudiant.h"
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

bool contrainte_cours_cours(Cours &p_cours1, Cours &p_cours2){
	//test si les horaires se chevauchent
	if( ((p_cours1.get_debut() <= p_cours2.get_debut + p_cours2.get_duree()) && (p_cours1.get_debut() >= p_cours2.get_debut())) 
	|| ((p_cours1.get_debut() + p_cours1.get_duree() <= p_cours2.get_debut + p_cours2.get_duree()) && (p_cours1.get_debut() + p_cours1.get_duree() >= p_cours2.get_debut()))
	)
	{
		//comparer les 2 liste etu
		if (p_cours1.get_liste_etu().size()>p_cours2.get_liste_etu().size())
		{
			for (int i = 0; i < p_cours1.get_liste_etu().size(); i++) {
				for (int y = 0; y < p_cours2.get_liste_etu().size(); y++) {
					if ( p_cours1.get_liste_etu().operator[i] == p_cours2.get_liste_etu().operator[y] )
					{ return false; }
				}
			}
		}
		else
		{
			for (int i = 0; i < p_cours2.get_liste_etu().size(); i++) {
				for (int y = 0; y < p_cours1.get_liste_etu().size(); y++) {
					if ( p_cours2.get_liste_etu().operator[i] == p_cours1.get_liste_etu().operator[y] )
					{ return false; }
				}
			}
		}
			
		//comparer num salle
		if ( p_cours1.get_num_salle() == p_cours2.get_num_salle() )
		{ return false; }
		
		//matrice de distance pour aller d une salle a lautre
	}
	else { return true; }
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
