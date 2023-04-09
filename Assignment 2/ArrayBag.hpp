/*
Rezwan Rahman
CSCI 235
Professor Oyekoya
Project 2: Array Bags and Sets
File: ArrayBag.hpp
*/

#ifndef ARRAY_BAG_
#define ARRAY_BAG_

#include <iostream>
#include <vector>
using namespace std;

template <class ItemType>
class ArrayBag
{
//public data members
public:

ArrayBag();
int getCurrentSize() const;
bool isEmpty() const;
bool add(const ItemType &new_entry);
bool remove(const ItemType &an_entry);
void clear();
bool contains(const ItemType &an_entry) const;
int getFrequencyOf(const ItemType &an_entry) const;
std::vector<ItemType> toVector() const;
void display() const;
bool duplicateItems();
void removeAllInstances(const ItemType &an_entry);
bool removeDuplicates();
void operator+=(const ArrayBag<ItemType> &a_bag);
void operator-=(const ArrayBag<ItemType> &a_bag);
void operator/=(const ArrayBag<ItemType> &a_bag);

//Protected data members
protected:
static const int DEFAULT_CAPACITY = 10; //max size of items_ at 10 by default for this project
ItemType items_[DEFAULT_CAPACITY];      // Array of bag items
int item_count_;                        // Current count of bag items

  /**
     @param target to be found in items_
     @return either the index target in the array items_ or -1,
     if the array does not contain the target.
     **/
int getIndexOf(const ItemType &target) const;

}; // end ArrayBag
#include "ArrayBag.cpp"
#endif //ending definition of ArrayBag
