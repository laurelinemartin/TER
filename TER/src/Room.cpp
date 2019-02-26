#include "Room.h"

int Room::nbRoom = 0;

Room::Room() : type(0), capacity(0), location(0)
{
    nbRoom += 1;
    id = nbRoom;
}

Room::Room(int p_type, int p_capacity) : type(p_type), capacity(p_capacity), location(0){ //without location
    nbRoom += 1;
    id = nbRoom;
}
Room::Room(int p_type, int p_capacity, int p_location) : type(p_type), capacity(p_capacity), location(p_location){ //with location
    nbRoom += 1;
    id = nbRoom;
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
    if (nb_etudiants > capacity)
        return false;
    return true;
}
bool Room::is_same_id(const Room& p_room){//verifie que 2 id de salle soit differents
    if(p_room.id == id)
        return true;
    return false;
}
void Room::descritpion(){
    cout<<"ROOM "<<this->get_id()<<" : "<<endl;
    cout<<"Room type : "<<this->get_type()<<endl;
    cout<<"Room id : "<<this->get_id()<<endl;
    cout<<"Room capacity : "<<this->get_capacity()<<endl;
    cout<<"Room location : "<<this->get_location()<<endl;
}



