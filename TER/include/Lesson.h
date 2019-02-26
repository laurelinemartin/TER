#ifndef LESSON_H
#define LESSON_H

#include <vector>
#include <iostream>
#include "Students.h"
using namespace std;

class Lesson
{
    public:
        //CTOR/DTOR
        Lesson();
        virtual ~Lesson();

        //GETTER
        double get_time() { return time; }
        int get_RoomType() { return RoomType; }
        int get_RoomId() { return RoomId; }
        int get_TeacherId() { return TeacherId; }
        int get_nbStudents() { return nbStudents;}

        //SETTER
        void set_time(double val) { time = val; }
        void set_RoomType(int val) { RoomType = val; }
        void set_RoomId(int val) { RoomId = val; }
        void set_TeacherId(int val) { TeacherId = val; }

        //TEST
        void addStudents(Students student);
        void description();

    protected:

    private:
        double time;
        int RoomType;
        int RoomId;
        int TeacherId;
        vector <Students*> StudentsList;
        int nbStudents;
};

#endif // LESSON_H
