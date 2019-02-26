#ifndef ROOM_H
#define ROOM_H

#include <iostream>

using namespace std;
class Room
{
    public:
        //CONSTRUCTEUR
        Room(); //default
        Room(int p_type, int p_capacity); //without location
        Room(int p_type, int p_capacity, int p_location); //with location
        ~Room();
         //GETTER
        int get_type() {return type;}
        int get_id() {return id;}
        int get_capacity() {return capacity;}
        int get_location() {return location;}
        //SETTER
        void set_type(int p_type) { type = p_type;}
        void set_capacity(int p_capacity) { capacity = p_capacity;}
        void set_location(int p_location) { location = p_location;}
        //TESTS
        bool test_capacity(int nb_etudiants); //test si la capacité est dépassée
        bool is_same_id(const Room& p_room);//verifie que 2 id de salle soit differents
        void descritpion();
    protected:

    private:
        static int id_count;
        int type; //{AMPHI = 0, TD = 1, TP = 2};
        int id;
        int capacity;
        int location; //Optionnal, nb de km de distance par rapport a l'arrêt de bus
};

#endif // ROOM_H
