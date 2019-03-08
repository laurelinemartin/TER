#ifndef Salle_H
#define Salle_H

#include <iostream>

using namespace std;
class Salle
{
    public:
        //CONSTRUCTEUR
        Salle(); //default
        Salle(int p_type, int p_capacity); //without location
        Salle(int p_type, int p_capacity, int p_location); //with location
        ~Salle();
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
        bool is_same_id(const Salle& p_Salle);//verifie que 2 id de salle soit differents
        void descritpion();
    protected:

    private:
        static int id_count;
        int type; //{AMPHI = 0, TD = 1, TP = 2};
        int id;
        int capacity;
        int location; //Optionnal, nb de km de distance par rapport a l'arrêt de bus
};

#endif // Salle_H
