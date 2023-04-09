#include <iostream>
#include "DoublyLinkedList.cpp"

using namespace std;

//main function
int main()
{
//create an object of DoublyLinkedList
DoublyLinkedList<char> d1;

//insert some value
d1.insert('E');
d1.insert('D');
d1.insert('C');
d1.insert('B');
d1.insert('A');

//display the list
d1.display();

//invert the list
d1.invert();

//display the list
d1.display();

//testing copy constructor
DoublyLinkedList<char> d2(d1);

//display the list
d2.display();

//backward display the list
d2.displayBackwards();

cout<<"Size = "<<d2.getSize()<<endl;

return 0;
}

