#ifndef Cours_H
#define Cours_H

#include <vector>
#include <iostream>
#include <algorithm>
#include "Etudiant.h"
#include "Enseignant.h"
using namespace std;

class Cours
{
    public:
        //CTOR/DTOR
        Cours(); //constructeur par défaut
        Cours(int p_num_cours, int p_duree, int p_type_salle,
              int p_num_salle, int p_num_ens, int p_debut,
              vector<int> p_liste_etu, vector<int> p_liste_ens);
        virtual ~Cours();

        //GETTER
       int get_num_cours(){return num_cours;}
       int get_duree(){return duree;}
       int get_type_salle(){return type_salle;}
       int get_num_salle(){return num_salle;}
       int get_num_ens(){return num_ens;}
       int get_debut(){return debut;}
       vector<int> get_liste_etu(){return liste_etu;}
       vector<int> get_liste_ens(){return liste_ens;}

        //SETTER
        void set_num_cours(int p_num_cours){num_cours = p_num_cours;}
        void set_duree(int p_duree){duree = p_duree;}
        void set_type_salle(int p_type_salle){type_salle = p_type_salle;}
        void set_num_salle(int p_num_salle){num_salle = p_num_salle;}
        void set_num_ens(int p_num_ens); //doit verifier que enseignant soit dans liste_ens
                                         //doit verifier que enseignant ai une plage compatible avec debut
        void set_debut(int p_debut){debut = p_debut;}

        //FONCTIONS DE BASE 
        void add_etu(int eleve);
        void add_enseignants(int enseignant);
        void description();

    protected:

    private:
        int num_cours; //identifiant du cours
        int duree; //représente la durée du cours en minutes
        int type_salle; // 0 : TP || 1 : autre salle 
        int num_salle; //identifiant de la salle 
        int num_ens; //identifiant du professeurs du cours
        int debut; //début d'un bloc de 15 min 
        vector<int> liste_etu; //tableau d'entier contenant les id d'étudaints participants au cours
        vector<int> liste_ens; //liste contenant les id des enseignants pouvant enseigner ce cours
};

#endif // Cours_H
