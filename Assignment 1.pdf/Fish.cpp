/*
Rezwan Rahman
CSCI 235
Professor Oyekoya
Project 1: OOP and Inheritance
File: Fish.cpp
*/

#include <iostream>
#include <cstdlib>
#include "Fish.hpp"

//default constructor
Fish::Fish(): Animal(), venomous_(false)
{
	
}
 //parameterized constructor
Fish::Fish(std::string name, bool domestic, bool predator) : 
Animal(name, domestic, predator), venomous_(false)
{
}
/** Checks to see if venomous_ is true @return venomous_
*/
bool Fish::isVenomous() const
{
	return venomous_;
}
/** Mutates venomous_ and sets it to true @post venomous_ is set to true
*/
void Fish::setVenomous()
{
	venomous_ = true;
}

/** @post displays fish data in the form:
"animal_name is [not] domestic, [it is / is not] a predator\n and it is [not] venomous.\n"
*/
void Fish::display() 
{
    std::cout<< name_ <<" is ";
    if(!isDomestic())
    std::cout<<"not domestic, ";
    else
    std::cout<<"domestic, ";
    if(!isPredator())
    std::cout<<"is not a predator \n";
    else
    std::cout<<"it is a predator \n";
    if(!isVenomous())
    std::cout<<"and it is not venomous.\n";
    else
    std::cout<<"and it is venomous.\n";
}
