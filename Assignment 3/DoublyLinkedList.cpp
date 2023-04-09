/*
Rezwan Rahman
CSCI 235
Professor Oyekoya
Project 3: Doubly <-> Linked List
File: DoubleNode.cpp
*/
#include "DoublyLinkedList.hpp"
#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

//default constructor, sets headPtr_ to null and itemCount_ to 0
template <class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList()
{
    headPtr_ = nullptr;
    itemCount_ = 0;
}//end default constructor

    /*
        Copy constructor that will make an exact copy of the list parameter, aList.
        This will make a deep copy of the list in the given parameter.
        You must iterate through the callee list parameter and insert nodes from aList into the caller list (the current one that isn't the parameter)
    */
template <class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList &aList)
{
    itemCount_ = aList.itemCount_;
    DoubleNode<ItemType> *temp = aList.getHeadPtr();//points to the node at the original chain 

    if(temp == nullptr)
    {
        headPtr_ = nullptr;
    }//end if

    else
    {
        //copy first node
        headPtr_ = new DoubleNode<ItemType>();
        headPtr_->setItem(temp->getItem());

        //copy remaining node
        DoubleNode<ItemType>* newChainPtr = headPtr_;
        DoubleNode<ItemType>* tailPtr = headPtr_;
        temp = temp->getNext();
        while(temp != nullptr)
        {
            ItemType nextItem = temp-> getItem();
            DoubleNode<ItemType>* newNodePtr = new DoubleNode<ItemType>(nextItem);
            newChainPtr-> setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
            newChainPtr->setPrevious(tailPtr);
            tailPtr = tailPtr->getNext();
            temp = temp->getNext();
        }//end while
    
        newChainPtr->setNext(nullptr); //end chain
    }//end else

    
}//end copy Constructor

//destructor that calls the clear function
template <class ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
    clear(); //Call the clear function as command for destructor
}

//return itemCount_
template <class ItemType>
int DoublyLinkedList<ItemType>::getSize() const 
{
    return itemCount_;
}//end getSize


    /* * 
        * Description: finds the node at parameter pos
        * Pre: pos is a valid place in the list, otherwise nullptr will be returned 
        * Post: returns a pointer to the node at pos
    * */
template <class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int &pos) const
{
    DoubleNode<ItemType>* temp = headPtr_;
    int i = 1;

    while (i != pos)
    {
        temp = temp->getNext();
        i++;
    }//end while
    return temp;
}//end getAtPos

template <class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr() const //return *headPtr_
{
    return headPtr_;
}// end getHeadPtr



    /* *
        * Description: inserts parameter item in caller list at parameter position
            *IMPORTANT: Position 1 is the first position, not 0
        * Pre: position is a valid place within the list, otherwise false will be returned
        * Post: returns true if the item has been inserted in the caller list 
        * Handles edge case of an invalid position parameter
        * Case: Inserting into head of the list
        * Case: Inserting into rear of the list
        * Case: Inserting into a position that is not an extremity 
    * */
template <class ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType &item, const int &position)
{
    DoubleNode<ItemType>* temp = headPtr_;
    DoubleNode<ItemType>* beforeTemp = headPtr_;
    DoubleNode<ItemType>* newNodePtr = new DoubleNode<ItemType>();
    newNodePtr->setItem(item);
    int Pos = 2; // Track the location of the pointers

    if(position<=0)
    {
        return false;
    }
    
    if (position == 1 && headPtr_ == nullptr) 
    { // If list is empty
        headPtr_ = newNodePtr;
        itemCount_++;
    } 
    else if (position == 1 && headPtr_ != nullptr) 
    { // If not empty
        newNodePtr->setNext(temp);
        temp->setPrevious(newNodePtr);
        temp = temp->getPrevious();
        headPtr_ = temp;
        itemCount_++;
    } 
    else 
    {
        temp = temp->getNext();
        while (Pos != position) {
            beforeTemp = beforeTemp->getNext();
            temp = temp->getNext();
            Pos++;
        }//end while
        if (temp == nullptr) {    // If inserting at end of list
            beforeTemp->setNext(newNodePtr);
            newNodePtr->setPrevious(beforeTemp);
        } else {    // Anywhere but the end of the list
            temp->setPrevious(newNodePtr);
            newNodePtr->setNext(temp);
            beforeTemp->setNext(newNodePtr);
            newNodePtr->setPrevious(beforeTemp);
        }
        itemCount_++;
    }
    return true;

}

    /* *
        * Description: removes node at parameter position
            *IMPORTANT: Position 1 is the first position, not 0
        * Pre: position is a valid place within the list, otherwise false will be returned
        * Post: returns true if the item at position has been removed from the caller list 
        * Handles edge case of invalid position parameter
        * Case: removing only node in list
        * Case: removing from the end
        * Case: removing from the beginning
        * Case: removing from a position that is not an extremity
    * */
template <class ItemType>
bool DoublyLinkedList<ItemType>::remove(const int &position)
{
    if(position < 1 || position > itemCount_)
    {
        return false;
    }//end if

    else
    {
        DoubleNode<ItemType> *temp;
        if(position == 1)
        {
            temp = headPtr_;
            headPtr_ = headPtr_->getNext();
            if(headPtr_ != nullptr)
            {
                headPtr_->setPrevious(nullptr);
            }//end if
            delete temp;
        }//end if
    
    

        else
        {
            DoubleNode<ItemType> *itr = headPtr_;
            for(int i = 2; i < position; i++)
            {
                temp = itr->getNext();
                if(itr->getNext()->getNext() != nullptr)
                {
                    itr->getNext()->getNext()->setPrevious(itr);
                    itr->setNext(itr->getNext()->getNext());
                }//end if
                else
                {
                    itr->setNext(nullptr);
                }
                delete temp;
            }//end for
        }
        itemCount_--;
        return true;
    }//end else
    

    
}// end remove

//returns true if itemCount_ is 0
template <class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const //returns true if itemCount_ is 0
{
    if(itemCount_ == 0)
    {
        return true;
    }//end if
    else
    {
        return false;
    }//end else
}//end isEmpty

    /* *
        * Description: removes all items from the caller list
        * Traverse through the linked list and delete each individual node
        * Post: no nodes remain in the list and itemCount_ is at 0
    * */
template <class ItemType>
void DoublyLinkedList<ItemType>::clear()
{
    DoubleNode<ItemType> *temp = headPtr_; //create temporary node
    while(headPtr_ != nullptr) //delete each node from list starting from head
    {
        headPtr_ = headPtr_->getNext();

        //return node to the system
        temp->setNext(nullptr);
        temp->setPrevious(nullptr);

        delete temp;
        temp = headPtr_;
    }// end while

    itemCount_ = 0;

}// end clear()

    //Iteratively outputs the contents of the caller list on the console
    //Example "A B C D E"
    //Note how theres no space at the end
template <class ItemType>
void DoublyLinkedList<ItemType>::display() const
{
    DoubleNode<ItemType>* temp = headPtr_;
    while(temp != nullptr)
    {
        cout<< temp->getItem();
        temp = temp->getNext();
        if(temp == nullptr)
        {
            cout<<'\n';
        }//end if
        else
        {
            cout<<' ';
        }//end else
    }//end while

}//end display

    //Iteratively outputs the contents of the caller list backwards on the console
    //Example if we had A B C D E we would instead display "E D C B A"
template <class ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const
{
    DoubleNode<ItemType>* temp = headPtr_;
    while(temp->getNext() != nullptr)
    {
        temp = temp->getNext();
    }//end while

    while(temp != nullptr)
    {
        cout<< temp->getItem();
        temp = temp->getPrevious();
        if(temp == nullptr)
        {
            cout<<'\n';
        }//end if
        else
        {
            cout<< ' ';
        }//end else
    }//end while
}//end DisplayBackwards

    // Reverses the list such that if my list was A B C D it will now be D C B A
    // Remember to change both previous and next pointers
    // Will be tested with both display and displayBackwards, make sure you have those working
template <class ItemType>
void DoublyLinkedList<ItemType>::invert()
{
    DoubleNode<ItemType> *temp = nullptr;
    DoubleNode<ItemType> *current = headPtr_;

    while (current != nullptr)
    {
        temp = current->getPrevious();
        current->setPrevious(current->getNext());
        current->setNext(temp);
        current = current->getPrevious();
    }//end while

    if(temp != nullptr )
    {
        headPtr_ = temp->getPrevious();
    }//end if

}//end invert()