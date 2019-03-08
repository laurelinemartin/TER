#include "../include/Teacher.h"

int Teacher::id_count = 0;

Teacher::Teacher() : DispoStart(0), DispoEnd(0)
{
    id_count += 1;
    id = id_count;
}

Teacher::~Teacher()
{
    //dtor
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
Teacher::Teacher(double p_DispoStart, double p_DispoEnd) : DispoStart(p_DispoStart), DispoEnd (p_DispoEnd)
{
    id_count += 1;
    id = id_count;
}

double Teacher::get_DispoStart()
{
    return DispoStart;
}

double Teacher::get_DispoEnd()
{
    return DispoEnd;
}

int Teacher::get_id()
{
    return id;
}

void Teacher::set_DispoStart(double p_DispoStart)
{
    DispoStart = p_DispoStart;
}

void Teacher::set_DispoEnd(double p_DispoEnd)
{
    DispoEnd = p_DispoEnd;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Teacher::description()
{
    cout<<"TEACHER "<<this->get_id()<<" : "<<endl;
    cout<<"DispoStart : "<<this->get_DispoStart()<<endl;
    cout<<"DispoEnd : "<<this->get_DispoEnd()<<endl;
}
