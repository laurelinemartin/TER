#include "Students.h"
int Students::id_count = 0;

Students::Students() : TransportTime(0), Transport(0), distance(0), flexibility(0)
{
    id_count+= 1;
    id = id_count;
}

Students::Students(int p_TransportTime, int p_Transport, double p_distance) : TransportTime(p_TransportTime), Transport(p_Transport), distance(p_distance), flexibility(0)
{
    id_count += 1;
    id = id_count;
}

Students::~Students()
{
    //dtor
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Students::set_flexibility(int p_flexibility)
{
    flexibility = p_flexibility;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Students::set_distance(double p_distance)
{
    distance = p_distance;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Students::set_transport(int p_transport)
{
    Transport = p_transport;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Students::set_transportTime(double p_transportTime)
{
    TransportTime = p_transportTime;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
int Students::get_id()
{
    return id;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
int Students::get_flexibility()
{
    return flexibility;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
double Students::get_distance()
{
    return distance;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
int Students::get_transport()
{
    return Transport;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
double Students::get_transportTime()
{
    return TransportTime;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Students::descritpion(){
    cout<<"STUDENT "<<this->get_id()<<" : "<<endl;
    cout<<"Transport Time : "<<this->get_transportTime()<<endl;
    cout<<"transport : "<<this->get_transport()<<endl;
    cout<<"distance : "<<this->get_distance()<<endl;
    cout<<"flexibility : "<<this->get_flexibility()<<endl;
}
