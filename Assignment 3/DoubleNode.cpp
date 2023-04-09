/*
Rezwan Rahman
CSCI 235
Professor Oyekoya
Project 3: Doubly <-> Linked List
File: DoubleNode.cpp
*/
#include "DoubleNode.hpp"
#include <iostream>
#include <cstddef>
using namespace std;

//default constructor, sets next_ and prev_ to nullptr
template<class ItemType>
DoubleNode<ItemType>::DoubleNode()
{
    next_ = nullptr;
    prev_ = nullptr; 
}//end Default constructor

//Parameterized Constructor, sets item_ to anItem, next_ to nextNodePtr, prev_ to previousNodePtr    
template<class ItemType>                                                          
DoubleNode<ItemType>::DoubleNode(const ItemType &anItem, DoubleNode<ItemType> *nextNodePtr, DoubleNode<ItemType> *previousNodePtr)
{
    item_ = anItem; 
    next_ = nextNodePtr;
    prev_ = previousNodePtr; 
}//end peramerized constructor

//sets item_ equal to anItem parameter
template<class ItemType>
void DoubleNode<ItemType>::setItem(const ItemType &anItem)
{
    item_ = anItem;
}//end setItem

//sets prev_ equal to previousNodePtr parameter        
template<class ItemType>                                                                                   
void DoubleNode<ItemType>::setPrevious(DoubleNode<ItemType> *previousNodePtr)
{
    prev_ = previousNodePtr;
}//end setPrevious

//sets next_ equal to nextNodePtr parameter
template<class ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType> *nextNodePtr)
{
    next_ = nextNodePtr;
}//end setNext

//returns item_
template<class ItemType>
ItemType DoubleNode<ItemType>::getItem() const
{
    return item_;
}//end getItem

//returns next_
template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext() const
{
    return next_;
}//end getNext     

//returns prev_
template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrevious() const
{
    return prev_;
}//end getPrevious