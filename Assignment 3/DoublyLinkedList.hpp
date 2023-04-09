/*
Rezwan Rahman
CSCI 235
Professor Oyekoya
Project 3: Doubly <-> Linked List
File: DoubleNode.cpp
*/
#ifndef DOUBLY_LINKED_LIST_
#define DOUBLY_LINKED_LIST_
#include "DoubleNode.cpp"

template <class ItemType>
class DoublyLinkedList
{
public:
    DoublyLinkedList(); 
    DoublyLinkedList(const DoublyLinkedList &aList);
    ~DoublyLinkedList(); 
    int getSize() const; 
    DoubleNode<ItemType> *getAtPos(const int &pos) const;
    DoubleNode<ItemType> *getHeadPtr() const; 
    bool insert(const ItemType &item, const int &position = 1);
    bool remove(const int &position);
    bool isEmpty() const; 
    void clear();
    void display() const;
    void displayBackwards() const;
    void invert();

private:    
    DoubleNode<ItemType> *headPtr_; //points to the first item in the linked list
    int itemCount_;                 //lists how many items are currently in the list
};

#include "DoublyLinkedList.cpp"
#endif
