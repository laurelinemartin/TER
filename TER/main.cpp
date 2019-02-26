#include "Room.h"

using namespace std;

int main()
{
    //TEST SUR LA CLASSE ROOM
    Room *test = new Room();
    test->descritpion();
    Room *test2 = new Room(0, 40);
    test2->descritpion();
    return 0;
}
