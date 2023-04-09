
#include <iostream>
#include <string>
using namespace std;
#include "Animal.cpp"
#include "Bird.cpp"
#include "Fish.cpp"
#include "Mammal.cpp"
int main()
{
string n="Eagle";
string m= "bat";
string b= "Parrot";
//creates an object for Bird and Fish classes and calls its methods
Fish Eagle(n);
Eagle.setDomestic();
Eagle.setVenomous();
Eagle.display();

Mammal Bat(m);
Bat.setDomestic();
Bat.setLegs(4);
Bat.setTail();
Bat.display();

Bird Parrot(b);
Parrot.setDomestic();
Parrot.setAquatic();
Parrot.display();

return 0;
}
