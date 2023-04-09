/*
Rezwan Rahman
CSCI 235
Professor Oyekoya
Project 1: OOP and Inheritance
File: Bird.cpp
*/
#include "Bird.hpp"
#include <cstdlib>

//default constructor
Bird::Bird() : Animal(), airborne_(false), aquatic_(false)
{//start default constructor
}//end default constructor

//parameterized constructor
Bird::Bird(std::string name, bool domestic, bool predator):
Animal(name, domestic, predator), airborne_(false), aquatic_(false)
{//start parameterized constructor

}//end perameterized constructor

/** Checks to see if Bird airborne_ is true @return airborne_
*/
bool Bird::isAirborne() const
{
	return airborne_;
}
/** Checks to see if Bird aquatic_ is true @return aquatic_
*/
bool Bird::isAquatic() const
{
	return aquatic_;
}
/** Mutates airborne_ and sets it to true @post airborne_ is set to true
*/
void Bird::setAirborne()
{
	airborne_ = true;
}
/** Mutates aquatic_ and sets it to true @post aquatic_ is set to true
*/
void Bird::setAquatic()
{
	aquatic_ = true;
}

/** @post displays bird data in the form:
“animal_name is [not] domestic and [it is / is not] a predator,\n it is [not] airborne and it is [not] aquatic.\n”
*/
void Bird::display() 
{
    std::cout<< name_ <<" is ";
    if(!isDomestic())
    std::cout<<"not domestic and ";
    else
    std::cout<<"domestic and ";
    if(!isPredator())
    std::cout<<"is not a predator, \n";
    else
    std::cout<<"it is a predator, \n";

    if(!isAirborne())
    std::cout<<"it is not airborne and it is ";
    else
    std::cout<<"it is airborne and it is ";
    if(!isAquatic())
    std::cout<<"not aquatic.\n";
    else
    std::cout<<"aquatic.\n";
}

//end Bird.cpp





