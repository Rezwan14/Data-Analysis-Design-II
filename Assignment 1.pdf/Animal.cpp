/*
Rezwan Rahman
CSCI 235
Professor Oyekoya
Project 1: OOP and Inheritance
File: Animal.cpp
*/

#include "Animal.hpp"
#include <cstdlib>

//default constructor: initialize all setter functions
Animal::Animal()
{//start default constructor
	name_ = "";
	domestic_ = false;
	predator_ = false;
}//end default constructor

//parameterized constructor
Animal::Animal(std::string name, bool domestic, bool predator)
{//start perameterized constructor
	name_ = name;
	domestic_ = domestic;
	predator_ = predator;
}//end perameterized constructor


//getName(): returns name_
std::string Animal::getName() const
{//start getName() function
	return name_;
}//end getName() function

//isDomestic(): returns domestic_
bool Animal::isDomestic() const
{//start isDomestic() function
	return domestic_;
}//end isDomestic() function

//isPredator(): returns predator_
bool Animal::isPredator() const
{//start isPredator() function
	return predator_;
}//end isPredator() function

//setName(): set name_ = name
void Animal::setName(std::string name)
{//start setName() function
	name_ = name;//set protected data member name_ to string name
}//end setName() function

//setDomestic(): set domestic_ = true
void Animal::setDomestic()
{//start setDomestic() function
	domestic_ = true;
}//end setDomestic() function

//setPredator(): 
void Animal::setPredator()
{//start setPredator() function
	predator_ = true;
}//end setPredator() function


