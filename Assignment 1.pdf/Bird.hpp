/*
Rezwan Rahman
CSCI 235
Professor Oyekoya
Project 1: OOP and Inheritance
File: Bird.hpp
*/

#ifndef BIRD_H_
#define BIRD_H_
#include "Animal.hpp"
//required libraries iostream & string
#include <iostream>
#include <string>

using namespace std;

//Bird class is a sub class of Animal
class Bird : public Animal
{
//public functions
public:

//******************************************************************//
//CONSTRUCTORS

//default constructor
Bird(); 

//parameterized constructor
Bird(std::string name, bool domestic = false, bool predator = false); 

//******************************************************************//
//GETTER FUNCTIONS

/** Checks to see if Bird airborne_ is true @return airborne_
*/
bool isAirborne() const;

/** Checks to see if Bird aquatic_ is true @return aquatic_
*/
bool isAquatic() const;

//******************************************************************//
//SETTER FUNCTIONS

/** Mutates airborne_ and sets it to true @post airborne_ is set to true
*/
void setAirborne();

/** Mutates aquatic_ and sets it to true @post aquatic_ is set to true
*/
void setAquatic();

//******************************************************************//
//DISPLAY FUNCTION

void display() override;

//protected data members
protected:
bool airborne_;
bool aquatic_;
};
#endif