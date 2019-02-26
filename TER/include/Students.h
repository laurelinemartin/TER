#ifndef STUDENTS_H
#define STUDENTS_H

#include <iostream>
using namespace std;
class Students
{
    public:
        //CTOR / DTOR
        Students();//Default
        Students(int p_TransportTime, int p_Transport, int p_distance);
        virtual ~Students();

        //GETTER
        double get_transportTime(){ return TransportTime;}
        int get_transport(){ return Transport;}
        int get_distance(){ return distance;}
        int get_flexibility(){ return flexibility;}
        int get_id(){ return id;}

        //SETTER
        void set_transportTime(double p_transportTime) { TransportTime = p_transportTime;}
        void set_transport(int p_transport){ Transport = p_transport;}
        void set_distance(int p_distance){distance = p_distance;}
        void set_flexibility(int p_flexibility){flexibility = p_flexibility;}

        //TEST
        void descritpion();
        void flexibility_evaluation();

    protected:

    private:
        static int id_count;
        double TransportTime;
        int Transport;
        int distance;
        int flexibility;
        int id ;

};

#endif // STUDENTS_H
