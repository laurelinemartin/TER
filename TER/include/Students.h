#ifndef STUDENTS_H
#define STUDENTS_H

#include <iostream>
using namespace std;
class Students
{
    public:
        //CTOR / DTOR
        Students();//Default
        Students(int p_TransportTime, int p_Transport, double p_distance);
        virtual ~Students();

        //GETTER
        double get_transportTime();
        int get_transport();
        double get_distance();
        int get_flexibility();
        int get_id();

        //SETTER
        void set_transportTime(double p_transportTime);
        void set_transport(int p_transport);
        void set_distance(double p_distance);
        void set_flexibility(int p_flexibility);

        //TEST
        void descritpion();

    protected:

    private:
        static int id_count;
        double TransportTime;
        int Transport;
        double distance;
        int flexibility;
        int id ;

};

#endif // STUDENTS_H
