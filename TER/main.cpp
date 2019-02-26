#include "Room.h"
#include "Students.h"

using namespace std;

int main()
{
    /*//TEST ON ROOM
    //CTOR
    //Default
    Room *testDefaultCtor = new Room();
    testDefaultCtor->descritpion();

    //without location
    Room *testWithoutLocCtor = new Room(0, 40);
    testWithoutLocCtor->descritpion();

    //with location
    Room *testWithLocCtor= new Room(1, 55, 3);
    testWithLocCtor->descritpion();

    cout<<testWithLocCtor->is_same_id(*testWithLocCtor)<<endl;*/

    //TEST ON STUDENTS
    //CTOR
    //Default
    Students *testDefaultCtor = new Students();
    testDefaultCtor->descritpion();

    Students *testCtor = new Students(20, 2, 22.3);
    testCtor->descritpion();

    return 0;
}
