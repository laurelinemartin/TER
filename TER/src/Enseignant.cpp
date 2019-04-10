#include "../include/Enseignant.h"

int Enseignant::id_count = 0;

Enseignant::Enseignant() : plage(0)
{
    id_count += 1;
    num_ens = id_count;
}

Enseignant::~Enseignant(){}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
Enseignant::Enseignant(vector<int> p_plage)
{
    id_count += 1;
    num_ens = id_count;
    plage = p_plage;
}

double Enseignant::get_plage(){
  return plage; }
double Enseignant::get_num_ens(){
  return num_ens;
}
void Enseignant::set_plage(double p_plage){
  plage = p_plage;}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Enseignant::description()
{
    cout<<"Enseignant "<<this->get_num_ens()<<" : "<<endl;
    cout<<"Plage disponibilités : "<<this->get_plage()<<endl;
}
