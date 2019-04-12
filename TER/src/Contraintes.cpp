#include "../include/Contraintes.h"

//~ Contraintes::Contraintes() : TransportTime(0), Transport(0), distance(0), flexibility(0)
//~ {
    //~ id_count+= 1;
    //~ id = id_count;
//~ }

//~ Contraintes::Contraintes(int id, vector<int> a(nbetu))
//~ {
    //~ identifiant = id;
    //~ for (int i = 0; i < nbeti; i++) {
		//~ etu_contraintes[i] = a[i]; }
//~ }

//~ Contraintes::~Contraintes() 
//~ {
 
//~ }

bool contrainte_cours_salle(Salle &p_salle, Cours &p_cours)
{
    if(p_cours.get_liste_etu().size() > p_salle.get_capacite())
        return false;
    if(p_salle.get_type_salle() != p_cours.get_type_salle())
        return false;
    return true;
}

bool contrainte_professeur_cours(Cours &p_cours)
{
    if(find(p_cours.get_liste_ens().begin(), p_cours.get_liste_ens().end(), p_cours.get_num_ens()) !=  p_cours.get_liste_ens().end())
        return true;
    return false;
}

bool contrainte_cours_cours (Cours &p_cours1, Cours &p_cours2)
{
	//test si les horaires se chevauchent
	if( ((p_cours1.get_debut() <= p_cours2.get_debut() + p_cours2.get_duree()) && (p_cours1.get_debut() >= p_cours2.get_debut())) 
	|| ((p_cours1.get_debut() + p_cours1.get_duree() <= p_cours2.get_debut() + p_cours2.get_duree()) && (p_cours1.get_debut() + p_cours1.get_duree() >= p_cours2.get_debut()))
	)
	{
		//comparer les 2 liste etu
		if (p_cours1.get_liste_etu().size()>p_cours2.get_liste_etu().size())
		{
			for (int i = 0; i < p_cours1.get_liste_etu().size(); i++) {
				for (int y = 0; y < p_cours2.get_liste_etu().size(); y++) {
					if ( p_cours1.get_liste_etu()[i] == p_cours2.get_liste_etu()[y] )
					{ return false; }
				}
			}
		}
		else
		{
			for (int i = 0; i < p_cours2.get_liste_etu().size(); i++) {
				for (int y = 0; y < p_cours1.get_liste_etu().size(); y++) {
					if ( p_cours2.get_liste_etu()[i] == p_cours1.get_liste_etu()[y] )
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
