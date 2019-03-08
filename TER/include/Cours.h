#ifndef Cours_H
#define Cours_H

#include <vector>
#include <iostream>
#include "Eleve.h"
using namespace std;

class Cours
{
    public:
        //CTOR/DTOR
        Cours();
        virtual ~Cours();

        //GETTER
        double get_time() { return time; }
        int get_SalleType() { return SalleType; }
        int get_SalleId() { return SalleId; }
        int get_TeacherId() { return TeacherId; }
        int get_nbEleve() { return nbEleve;}

        //SETTER
        void set_time(double val) { time = val; }
        void set_SalleType(int val) { SalleType = val; }
        void set_SalleId(int val) { SalleId = val; }
        void set_TeacherId(int val) { TeacherId = val; }

        //TEST
        void addEleve(Eleve student);
        void description();

    protected:

    private:
        double time;
        int SalleType;
        int SalleId;
        int TeacherId;
        vector <Eleve*> EleveList;
        int nbEleve;
};

#endif // Cours_H
