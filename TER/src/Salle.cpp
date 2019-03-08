#include "../include/Salle.h"

int Salle::id_count = 0;

/** @brief (one liner)
  *
  * (documentation goes here)
  */
Salle::Salle() : type(0), capacity(0), location(0)
{
    id_count += 1;
    id = id_count;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
Salle::Salle(int p_type, int p_capacity) : type(p_type), capacity(p_capacity), location(0){ //without location
    id_count += 1;
    id = id_count;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
Salle::Salle(int p_type, int p_capacity, int p_location) : type(p_type), capacity(p_capacity), location(p_location){ //with location
    id_count += 1;
    id = id_count;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
Salle::~Salle(){
}

///TESTS

/** @brief (one liner)
  *
  * (documentation goes here)
  */
bool Salle::test_capacity(int nb_etudiants){//test si la capacité est dépassée
    if (nb_etudiants > capacity)
        return false;
    return true;
}/** @brief (one liner)
  *
  * (documentation goes here)
  */

/** @brief (one liner)
  *
  * (documentation goes here)
  */
bool Salle::is_same_id(const Salle& p_Salle){//verifie que 2 id de salle soit differents
    if(p_Salle.id == id)
        return true;
    return false;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Salle::descritpion(){
    cout<<"Salle "<<this->get_id()<<" : "<<endl;
    cout<<"type : "<<this->get_type()<<endl;
    cout<<"capacity : "<<this->get_capacity()<<endl;
    cout<<"location : "<<this->get_location()<<endl;
}



