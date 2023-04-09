/*
Rezwan Rahman
CSCI 235
Professor Oyekoya
Project 1: OOP and Inheritance
File: Mammal.hpp
*/

#ifndef MAMMAL_H_
#define MAMMAL_H_
#include <iostream>
#include <string>
using namespace std;
#include "Animal.hpp"

class Mammal : public Animal
{
public:
//default constructor
Mammal();

//peramaterized constructor
Mammal(std::string name, bool domestic = false, bool predator = false); 
bool hasHair() const;

//getters
bool isAirborne() const;
bool isAquatic() const;
bool isToothed() const;
bool hasFins() const;
bool hasTail() const;
int legs() const;

//setters
//set our private data member to true
void setHair();
void setAirborne(); 
void setAquatic();
void setToothed(); 
void setFins();
void setTail();
//set private data member legs_ to legs
void setLegs(int legs);

/** @post displays bird data in the form:
"animal_name is [not] domestic and [it is / is not] a predator,\n
it is [not] airborne and it is [not] aquatic,\n
it has [no] hair, [no] teeth, [no] fins, [no] tail and legs_ legs.\n”
*/
void display() override;

protected:
bool hair_;
bool airborne_;
bool aquatic_;
bool toothed_;
bool fins_;
bool tail_;
int legs_;


};

#endif


