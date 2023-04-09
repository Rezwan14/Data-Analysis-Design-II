/*
Rezwan Rahman
CSCI 235
Professor Oyekoya
Project 3: Doubly <-> Linked List
File: DoubleNode.hpp
*/

#ifndef DOUBLE_NODE_
#define DOUBLE_NODE_
#include <iostream>
using namespace std; 

template <class ItemType> //Reminder this is a template class, implement the .cpp accordingly
class DoubleNode
{
public:
DoubleNode();                                                                                                                     //default constructor, sets next_ and prev_ to nullptr
DoubleNode(const ItemType &anItem, DoubleNode<ItemType> *nextNodePtr = nullptr, DoubleNode<ItemType> *previousNodePtr = nullptr); //Parameterized Constructor, sets item_ to anItem, next_ to nextNodePtr, prev_ to previousNodePtr
//setters:
void setItem(const ItemType &anItem);                                                                                             //sets item_ equal to anItem parameter
void setPrevious(DoubleNode<ItemType> *previousNodePtr);                                                                          //sets prev_ equal to previousNodePtr parameter
void setNext(DoubleNode<ItemType> *nextNodePtr);                                                                                  //sets next_ equal to nextNodePtr parameter
//getters:
ItemType getItem() const;                  //returns item_
DoubleNode<ItemType> *getNext() const;     //returns next_
DoubleNode<ItemType> *getPrevious() const; //returns prev_

private:
ItemType item_;              //actual content of your node
DoubleNode<ItemType> *next_; //pointer to the node that is after this node
DoubleNode<ItemType> *prev_; //pointer to the node that is before this node
}; //end DoubleNode


#endif