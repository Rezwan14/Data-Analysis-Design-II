/*
Rezwan Rahman
CSCI 235
Professor Oyekoya
Project 1: OOP and Inheritance
File: Mammal.cpp
*/
#include "Mammal.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;
//Constructor
Mammal::Mammal(): Animal(), hair_(false), airborne_(false), aquatic_(false), toothed_(false), fins_(false), tail_(false), legs_(0) 
{
}

//perameterized constructor
Mammal::Mammal(std::string name, bool domestic, bool predator): 
Animal(name, domestic, predator), hair_(false), airborne_(false), aquatic_(false), toothed_(false), fins_(false), tail_(false), legs_(0)
{
} 
//hasHair(): return hair_
bool Mammal::hasHair() const
{//start hashair()
	return hair_;
}//end hasHair()

//isAirborne(): return airborne_
bool Mammal::isAirborne() const
{//start isAirborne()
	return airborne_;
}//end isAirborne()

//isAquatic(): return aquatic_
bool Mammal::isAquatic() const
{//start isAquatic()
	return aquatic_;
}//end isAquatic()

//isToothed(): return toothed_
bool Mammal::isToothed() const
{//begin isToothed
	return toothed_;
}//end isToothed

//hasFins(): return fins_
bool Mammal::hasFins() const
{//start hasFins()
	return fins_;
}//end hasFins_

//hasTail(): return tail_
bool Mammal::hasTail() const
{//start hasTail()
	return tail_;
}//end hasTail()

//legs():return legs_
int Mammal::legs() const
{//start legs()
	return legs_;
}//end legs()

//setHair(): set protected data member to true
void Mammal::setHair()
{//start setHair()
	hair_ = true;
}//end setHair()

//setAirborne(): set protected data member to true
void Mammal::setAirborne()
{//start setAirborne
	airborne_ = true;
}//end setAirborne

//setAquatic(): set protected data member to true
void Mammal::setAquatic()
{//start setAquatic()
	aquatic_ = true;
}//end setAquatic()

//setToothed(): set protected data member to true
void Mammal::setToothed()
{//start setToothed
	toothed_ = true;
}//end setToothed

//setFins(): set protected data member to true
void Mammal::setFins()
{//start setFins()
	fins_ = true;
}//end setFins()

//setTail(): set protected data member to true
void Mammal::setTail()
{//start setTail()
	tail_ = true;
}//end setTail()

//setLegs(): set set protected data member legs_ equal to legs
void Mammal::setLegs(int legs)
{//start setLegs()
	legs_ = legs;
}//end setLegs()

/** @post displays bird data in the form:
"animal_name is [not] domestic and [it is / is not] a predator,\n
it is [not] airborne and it is [not] aquatic,\n
it has [no] hair, [no] teeth, [no] fins, [no] tail and legs_ legs.\n”
*/
void Mammal::display() 
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
    std::cout<<"not aquatic, \n";
    else
    std::cout<<"aquatic, \n";
	if(!hasHair())
	std::cout<< "it has no hair, ";
	else
	std::cout<< "it has hair, ";
	if(!isToothed())
	std::cout<<"no teeth, ";
	else
	std::cout<<"teeth, ";
	if(!hasFins())
	std::cout<<"no fins, ";
	else
	std::cout<<"fins, ";
	if(!hasTail())
	std::cout<<"no tail and ";
	else
	std::cout<<"tail and ";
	if(!legs())
	std::cout<< legs_ << " legs.\n";
	else
	std::cout<< legs_ << " legs.\n";
}






