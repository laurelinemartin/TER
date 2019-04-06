#include "../include/Enseignant.h"

int Enseignant::id_count = 0;

Enseignant::Enseignant() : DispoStart(0), DispoEnd(0)
{
    id_count += 1;
    id = id_count;
}

Enseignant::~Enseignant()
{
    //dtor
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
Enseignant::Enseignant(double p_DispoStart, double p_DispoEnd) : DispoStart(p_DispoStart), DispoEnd (p_DispoEnd)
{
    id_count += 1;
    id = id_count;
}

double Enseignant::get_DispoStart()
{
    return DispoStart;
}

double Enseignant::get_DispoEnd()
{
    return DispoEnd;
}

void Enseignant::set_DispoStart(double p_DispoStart)
{
    DispoStart = p_DispoStart;
}

void Enseignant::set_DispoEnd(double p_DispoEnd)
{
    DispoEnd = p_DispoEnd;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Enseignant::description()
{
    cout<<"Enseignant "<<this->get_id()<<" : "<<endl;
    cout<<"DispoStart : "<<this->get_DispoStart()<<endl;
    cout<<"DispoEnd : "<<this->get_DispoEnd()<<endl;
}
