/*
Rezwan Rahman
CSCI 235
Professor Oyekoya
Project 1: OOP and Inheritance
File: Fish.hpp
*/

#ifndef FISH_H_
#define FISH_H_
//required libraries iostream & string
#include <iostream>
#include <string>

using namespace std;
#include "Animal.hpp"

class Fish : public Animal
{
public:
//Constructors
Fish(); //default constructor

Fish(std::string name, bool domestic = false, bool predator = false); //parameterized constructor

/** Checks to see if venomous_ is true @return venomous_
*/
// getter function
bool isVenomous() const;
/** Mutates venomous_ and sets it to true @post venomous_ is set to true
*/

//setter function
void setVenomous();

/** @post displays fish data in the form:
"animal_name is [not] domestic, [it is / is not] a predator\n and it is [not] venomous.\n"
*/
void display() override;


//protected data members
protected: 
bool venomous_;
};
#endif
//End Fish.hpp


