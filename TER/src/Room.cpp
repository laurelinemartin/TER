#include "Room.h"

Room::Room()
{
    this->type = 0;
    this->id = 0;
    this->capacity = 0;
    this->location = 0;
}

Room::~Room()
{
    //dtor
}

Room::Room(const Room& other)
{
    //copy ctor
}

//GETTER
int Room::get_type(){
    return this->type;
}
int Room::get_id(){
    return this->id;
}
int Room::get_capacity(){
    return this->capacity;
}
int Room::get_location(){
    return this->location;
}
//SETTER
void Room::set_type(int p_type){
    this->type = p_type;
}
void Room::set_id(int p_id){
    this->id = p_id;
}
void Room::set_capacity(int p_capacity){
    this->capacity = p_capacity;
}
void Room::set_location(int p_location){
    this->location = p_location;
}
//TESTS
bool Room::test_capacity(int nb_etudiants){//test si la capacité est dépassée
    return true;
}
bool Room::test_id(Room p_room){//verifie que 2 id de salle soit differents
    return true;
}
void Room::descritpion(){
    cout<<"Room type : "<<this->get_type()<<endl;
    cout<<"Room id : "<<this->get_id()<<endl;
    cout<<"Room capacity : "<<this->get_capacity()<<endl;
    cout<<"Room location : "<<this->get_location()<<endl;
}



