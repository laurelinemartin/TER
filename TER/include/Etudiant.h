#ifndef Etudiant_H
#define Etudiant_H

#include <iostream>
using namespace std;
class Etudiant
{
    public:
        //CTOR / DTOR
        Etudiant();//Default
        Etudiant(int p_distance, int p_heure_debut);
        virtual ~Etudiant();

        //GETTER
        int get_num_etu(){return num_etu;}
        int get_distance(){return distance;}
        int get_contrainte(){return contrainte;}
        int get_heure_debut(){return heure_debut;}

        //SETTER
        void set_distance(int p_distance){distance = p_distance;}
        void set_contrainte(int p_contrainte){contrainte = p_contrainte;}
        void set_heure_debut(int p_heure_debut){heure_debut = p_heure_debut;}
        
        //FONCTIONS DE BASE
        void description();

    protected:

    private:
        static int id_count;
        int num_etu;
        int distance; //0 = -15min | 1 = entre 15 et 45min | 2 = plus de 45min
        int contrainte; //0 = aucune contrainte | 1 = contrainte travail | 2 = contrainte enfant | 3 = contraintes 1 et 2
        int heure_debut; 
        

};

#endif // Eleve_H
