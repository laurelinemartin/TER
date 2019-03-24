#include "../include/Salle.h"

int Salle::id_count = 0;

/** @brief Constructeur de la salle
  * 
  */
Salle::Salle() : type(0), capacity(0), location(0){
    id_count += 1;
    id = id_count;
}

/** @brief Constructeur
  */
Salle::Salle(int p_type, int p_capacity) : type(p_type), capacity(p_capacity), location(0){ //without location
    id_count += 1;
    id = id_count;
}

/** @brief Constructeur
  */
Salle::Salle(int p_type, int p_capacity, int p_location) : type(p_type), capacity(p_capacity), location(p_location){ //with location
    id_count += 1;
    id = id_count;
}


/** @brief Destructateur
  */
Salle::~Salle(){
}

///TESTS

/** @brief Teste si la capaciter de la salle est dépassée
  * Prends en argument un nombre d'étudiant. Renvoie faut si le nombre d'étudiant est
  * supérieur à la capacité de la salle, vrai sinon.
  */
bool Salle::test_capacity(int nb_etudiants){
    if (nb_etudiants > capacity)
        return false;
    return true;
}

/** @brief Teste si deux IDs de salles sont identiques.
  * Prend en argument une salle. Revoie vrai si les deux salles sont idéntiques,
  * faux sinon.
  */
bool Salle::is_same_id(const Salle& p_Salle){
    if(p_Salle.id == id)
        return true;
    return false;
}

/** @brief Affiche dans le terminal les informations de la salle
  */
void Salle::descritpion(){
    cout<<"Salle "<<this->get_id()<<" : "<<endl;
    cout<<"type : "<<this->get_type()<<endl;
    cout<<"capacity : "<<this->get_capacity()<<endl;
    cout<<"location : "<<this->get_location()<<endl;
}



