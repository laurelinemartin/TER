#include "Room.h"

using namespace std;

int main()
{
    //TEST SUR LA CLASSE ROOM
    //Constructeurs
    //Default
    Room *testDefaultCtor = new Room();
    testDefaultCtor->descritpion();

    //without location
    Room *testWithoutLocCtor = new Room(0, 40);
    testWithoutLocCtor->descritpion();

    //with location
    Room *testWithLocCtor= new Room(1, 55, 3);
    testWithLocCtor->descritpion();

    cout<<testWithLocCtor->is_same_id(*testWithLocCtor)<<endl;

    return 0;
}
