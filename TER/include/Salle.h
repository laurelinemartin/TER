#ifndef Salle_H
#define Salle_H

#include <iostream>

using namespace std;
class Salle
{
    public:
        //CONSTRUCTEUR
        Salle(); //default
        Salle(int p_type_salle, int p_capacite);
        Salle(int p_type_salle, int p_capacite, int p_localisation);
        ~Salle();

        //GETTER
        int get_num_salle() {return num_salle;}
        int get_localisation() {return localisation;}
        int get_type_salle() {return type_salle;}
        int get_capacite() {return capacite;}

        //SETTER
        void set_localisation(int p_localisation) { localisation = p_localisation;}
        void set_type_salle(int p_type_salle) { type_salle = p_type_salle;}
        void set_capacite(int p_capacite) { capacite = p_capacite;}

        //FONCTIONS DE BASE
        bool test_capacite(int nb_etudiants); //test si la capacité est dépassée
        bool test_num_salle(const Salle& p_Salle);//verifie que 2 id de salle soit differents
        void descritpion();

    protected:

    private:
        static int id_count; //utilisé pour l'identifiant unique d'une salle
        int num_salle; 
        int localisation; //0 = proche; 1 = moderement eloigné; 2 = eloigné
        int type_salle; //0 = salle de TP; 1 = autre
        int capacite;
};

#endif // Salle_H
