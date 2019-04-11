#include "../include/Etudiant.h"
int Etudiant::id_count = 0;

Etudiant::Etudiant() : distance(0), contrainte(0), heure_debut(0)
{
    id_count+= 1;
    num_etu = id_count;
}

Etudiant::Etudiant(int p_distance, int p_heure_debut) : distance(p_distance), heure_debut(p_heure_debut), contrainte(0)
{
    id_count += 1;
    num_etu = id_count;
}

Etudiant::~Etudiant()
{
    //dtor
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Etudiant::description(){
    cout<<"Etudiant : "<<this->get_num_etu()<<endl;
    cout<<"distance : "<<this->get_distance()<<endl;
    cout<<"contrainte : "<<this->get_contrainte()<<endl;
    cout<<"heure_debut : "<<this->get_heure_debut()<<endl;
}
