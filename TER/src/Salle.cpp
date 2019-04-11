#include "../include/Salle.h"

int Salle::id_count = 0;

/** @brief Constructeur de la salle
  * 
  */
Salle::Salle() : type_salle(0), capacite(0), localisation(0){
    id_count += 1;
    num_salle = id_count;
}

/** @brief Constructeur
  */
Salle::Salle(int p_type_salle, int p_capacite) : type_salle(p_type_salle), capacite(p_capacite), localisation(0){ //without location
    id_count += 1;
    num_salle = id_count;
}

/** @brief Constructeur
  */
Salle::Salle(int p_type_salle, int p_capacite, int p_localisation) : type_salle(p_type_salle), capacite(p_capacite), localisation( p_localisation){ //without location
    id_count += 1;
    num_salle = id_count;
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
bool Salle::test_capacite(int nb_etudiants){
    if (nb_etudiants > capacite)
        return false;
    return true;
}

/** @brief Teste si deux IDs de salles sont identiques.
  * Prend en argument une salle. Revoie vrai si les deux salles sont idéntiques,
  * faux sinon.
  */
bool Salle::test_num_salle(const Salle& p_Salle){
    if(p_Salle.num_salle == this->num_salle)
        return true;
    return false;
}

/** @brief Affiche dans le terminal les informations de la salle
  */
void Salle::description(){
    cout<<"num_salle :  "<<this->get_num_salle()<<endl;
    cout<<"type_salle : "<<this->get_type_salle()<<endl;
    cout<<"capacite : "<<this->get_capacite()<<endl;
    cout<<"localisation : "<<this->get_localisation()<<endl;
}



