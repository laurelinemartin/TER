#include "../include/Enseignant.h"

int Enseignant::id_count = 0;

Enseignant::Enseignant()
{
    id_count += 1;
    num_ens = id_count;
}

Enseignant::Enseignant(vector<int> p_plage) : plage(p_plage)
{
    id_count += 1;
    num_ens = id_count;
}

Enseignant::~Enseignant(){}

void Enseignant::add_dispo(int dispo){
  plage.push_back(dispo);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Enseignant::description()
{
    cout<<"Enseignant : "<<this->get_num_ens()<<endl;
    cout<<"Plage disponibilités : "<<endl;
    for(int i = 0; i < this->plage.size(); i ++){
        cout<<this->plage[i]<<endl;
    }
}
