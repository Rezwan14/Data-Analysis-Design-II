/*
Rezwan Rahman
CSCI 235
Professor Oyekoya
Project 1: OOP and Inheritance
Due: September 20th, 2021
File: Animal.hpp
*/

#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
using namespace std;


class Animal
{
//PUBLIC: Stored functions
public:
//default constructor
Animal(); 
//parameterized constructor
Animal(std::string name, bool domestic = false, bool predator = false); 

//GETTER FUNCTIONS: returns private data members

//getName(): returns name_
std::string getName() const;
//isDomestic(): returns domestic_ 
bool isDomestic() const;
//isPredator(): returns predator_ 
bool isPredator() const;

//SETTER FUNCTIONS:set private data members to true

//setName():set name_ = name;
void setName(std::string name);
//setDomestic(): set domestic_ = true
void setDomestic();
//setPredator(): set predator_ = true
void setPredator();

//DISPLAY FUNCTION: virtual function
//display(): dont include virtual function in cpp file
virtual void display() = 0;

//protected data members
protected:
std::string name_;
bool domestic_;
bool predator_; 

}; //end Animal class
#endif



