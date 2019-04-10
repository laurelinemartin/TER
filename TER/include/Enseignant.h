#ifndef Enseignant_H
#define Enseignant_H

#include <iostream>
using namespace std;
class Enseignant
{
    public:
        Enseignant();
        Enseignant (double p_DispoStart, double DispoEnd);
        virtual ~Enseignant();
        double get_DispoStart();
        double get_DispoEnd();
        int get_id(){return id;}
        void set_DispoStart(double p_DispoStart);
        void set_DispoEnd(double p_DispoEnd);
        void description();

    protected:

    private:
        static int id_count;
        int id;
        double DispoStart; //probablement à modifier
        double DispoEnd;
};

#endif // Enseignant_H
