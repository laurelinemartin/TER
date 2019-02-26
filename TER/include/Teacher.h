#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
using namespace std;
class Teacher
{
    public:
        Teacher();
        Teacher (double p_DispoStart, double DispoEnd);
        virtual ~Teacher();
        double get_DispoStart();
        double get_DispoEnd();
        int get_id();
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

#endif // TEACHER_H
