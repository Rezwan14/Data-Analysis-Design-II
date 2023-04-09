/*
Rezwan Rahman
CSCI 235
Professor Oyekoya
Project 2: Array Bags and Sets
File: ArrayBag.cpp
*/

#include "ArrayBag.hpp"
#include <iostream>
#include <string>

/** default constructor**/
template <class ItemType>
ArrayBag<ItemType>::ArrayBag(): item_count_(0) 
{
}//end Default Constructor


//@return item_count_ : the current size of the bag
template <class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
  return item_count_; 
}//end getCurrentSize()


//@return true if item_count_ == 0, false otherwise
template <class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
  return item_count_ == 0;
}//end isEmpty()


//@return true if new_entry was successfully added to items_, false otherwise
template <class ItemType>
bool ArrayBag<ItemType>::add(const ItemType &new_entry)
{
  bool hasRoomToAdd = (item_count_ < DEFAULT_CAPACITY);
  bool canAdd = getIndexOf(new_entry) == -1;
  if(hasRoomToAdd && canAdd)
  {
    items_[item_count_] = new_entry;
    item_count_++;
    return true;
  }//end if

  return false;
  }//end add()

 
//@return true if an_entry was successfully removed from items_, false otherwise
template <class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType &an_entry)
{
  int locatedIndex = getIndexOf(an_entry);
  bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
  if(canRemoveItem)
  {
    item_count_--;
    items_[locatedIndex] = items_[item_count_];
  }//end if
  return canRemoveItem;
}// end Remove()


//@post item_count_ == 0
template <class ItemType>
void ArrayBag<ItemType>::clear()
{
  item_count_ = 0;
}// end clear()


//@return true if an_entry is found in items_, false otherwise
template <class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType &an_entry) const
{
  return getIndexOf(an_entry) > -1;
}// end contains

  /**
    @return the number of times an_entry is found in items_
  **/
template <class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType &an_entry) const
{
  int frequency = 0;
  int curIndex = 0; //current array index
  while(curIndex < item_count_)
  {
    if(items_[curIndex] == an_entry)
    {
      frequency++;
    }//end if

    curIndex++;
  }//end While

  return frequency;
} // end getFrequncyOf

  /**
    @return a vector having the same contents as items_
    **/
template <class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
  std::vector<ItemType> bagContents;
  for(int i=0; i < item_count_; i++)
    bagContents.push_back(items_[i]);

  return bagContents;
}//end toVector

  /**
    @post prints the contents of items_ to the standard output separated by commas and followed by a new line.
    Example: A, B, C, D, E\n
    Note how there is no comma and space for the last item.
	**/
template <class ItemType>
void ArrayBag<ItemType>::display() const
{
  for(int i = 0; i < item_count_; i++)
  {
    //if final item
    if(i == item_count_ - 1)
    {
      std::cout<< items_[i]; //print the item
    }// end if

    //otherwise
    else
    {
      std::cout<< items_[i] << ", "; //print item followed by comma
    }//end else

  }//end for

  std::cout<<std::endl; //print entire set

}//end display()


  /**
      duplicate all the items in the bag 
      meaning that for every item in the bag we add another copy of it. 
      Example: we originally have [A, B] and after duplication we have [A, B, A, B] or [A, A, B, B] or how ever order you want so long as there are 2 A's and 2 B's
      Return true if successfully duplicated 
      but return false if there is nothing to duplicate or if we go above the DEFAULT_CAPACITY which is 10 for this project
    */


template <class ItemType>
bool ArrayBag<ItemType>::duplicateItems()
{
  
}

  /**
    @post every instance of an_entry is removed
  */
template <class ItemType>
void ArrayBag<ItemType>::removeAllInstances(const ItemType &an_entry)
{
}// end removeAllInstances

  /**
    @return true if we managed to remove all items that have duplicates in the bag
    Example: a duplicate would be [A, B, C, C, D, D, D, E]
    What we should have after running this function: [A, B, C, D, E] (may be out of order depending on how you do it, that doesn't matter)
    @return false if there are 1 or less items in the bag
  */
template <class ItemType>
bool ArrayBag<ItemType>::removeDuplicates()
{
  
}

  /* ---------- OPERATOR OVERLOADS ----------*/

  /** 
    implements Set Union. The union of two sets A and B is the set of elements which are in A, in B, or in both A and B.  
		@param a_bag to be combined with the contents of this (the calling) bag
		@post adds as many items from a_bag as space allows    
	*/
template <class ItemType>
void ArrayBag<ItemType>::operator+=(const ArrayBag<ItemType> &a_bag)
{
  std::vector<ItemType> v = a_bag.toVector(); //use v to represent items_ for a_bag
  for(int i=0; i < v.size(); i++)
  {
    if(item_count_ != DEFAULT_CAPACITY)
    {
      add(v[i]);
    }//end if


  }//end for
}//end +=

  /** 
    implements Set Difference  The (set) difference between two sets A and B is the set that consists of the elements of A which are not elements of  B 
		@param a_bag to be subtracted from this (the calling) bag
		@post removes all data from items_ that is also found in a_bag
    Example if A has [1, 2, 3, 4, 5] and B has [4, 5, 6, 7], then A-=B will result in A containing [1, 2, 3] and B remaining the same
	*/
template <class ItemType>
void ArrayBag<ItemType>::operator-=(const ArrayBag<ItemType> &a_bag)
{
  std::vector<ItemType> v = a_bag.toVector();
  for(int i = 0; i < v.size(); i++)
  {
    remove(v[i]);
  }//end for
}//end -=

  /** 
    implements Set Intersection  The intersection of two sets A and B is the set that consists of the elements that are in both A and B 
		@param a_bag to be intersected with this (the calling) bag
		@post items_ no longer contains data not found in a_bag    
    Example if bag A has [1,2,3,4,5] and Bag B has [7,8,5,9] then A /= B will result in A containing only 5 since 5 is found in both bag A and bag B
	*/
template <class ItemType>
void ArrayBag<ItemType>::operator/=(const ArrayBag<ItemType> &a_bag)
{
  for(int i = item_count_ - 1; i >= 0; i--)
  {
    if(!a_bag.contains(items_[i]))
    {
      remove(items_[i]);
    }//end if
  }// end for
}//end /=


//Private member function
template <class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType &target) const
{
  bool isFound = false;
  int result = -1;
  int searchIndex = 0;

  //if the bag is empty, itemCount is zero, so loop is skipped
  while(!isFound && (searchIndex < item_count_))
  {
    if(items_[searchIndex] == target)
    {
      isFound = true;
      result = searchIndex;
    }//end if
  
    else
    {
      searchIndex++;
    }//end else
  }//end while

  return result; 
}// end getIndexOf
