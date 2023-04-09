#include "ArrayBag.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

using std::cout;
using std::endl;
using std::string;

void displayBag(ArrayBag<std::string>& bag) {

   cout << "The bag contains " << bag.getCurrentSize()

        << " items:" << endl;

   std::vector<string> setItems = bag.toVector();

   int numberOfEntries = (int)setItems.size();

   for (int i = 0; i < numberOfEntries; i++) {

      cout << setItems[i] << " ";

   } // end for

   cout << endl << endl;

} // end displaySet

void bagTester(ArrayBag<string>& bag) {

   cout << "isEmpty: returns " << bag.isEmpty()

        << "; should be 1 (true)" << endl;

   displayBag(bag);

   std::string items[] = {"one", "two", "three", "four", "five",};

   cout << "Add 5 items to the bag: " << endl;

   for (int i = 0; i < 5; i++) {

          bag.add(items[i]);

   } // end for

   displayBag(bag);

   cout << "isEmpty: returns " << bag.isEmpty()

        << "; should be 0 (false)" << endl;

   cout << "getCurrentSize: returns " << bag.getCurrentSize()

        << "; should be 5" << endl;

   cout << "Try to add another entry: add(\"extra\") returns "

        << bag.add("extra") << endl;

       cout << "contains(\"three\"): returns " << bag.contains("three")

        << "; should be 1 (true)" << endl;

   cout << "contains(\"ten\"): returns " << bag.contains("ten")

        << "; should be 0 (false)" << endl;

   cout << "remove(\"one\"): returns " << bag.remove("one")

        << "; should be 1 (true)" << endl;

   cout << "remove(\"one\"): returns " << bag.remove("one")

        << "; should be 0 (false)" << endl;

   cout << endl;

   displayBag(bag);

   cout << "After clearing the bag, ";

   bag.clear();

   cout << "isEmpty: returns " << bag.isEmpty()

        << "; should be 1 (true)" << endl;

} // end setTester

int main() {

   ArrayBag<std::string> bag1, bag2;

   cout << "Testing the Array-Based Bag:" << endl;

   cout << "The initial bag is empty." << endl;

   bagTester(bag1);

   bag1.add("one");

   bag1.add("two");

   bag1.add("three");

   bag2.add("one");

   bag2.add("four");

   bag2.add("five");

   cout<<endl;

   cout<<"Bag1 : "<<endl;

   displayBag(bag1);

   cout<<"Bag2 : "<<endl;

   displayBag(bag2);

   

   cout << "All done!" << endl;

   return 0;

} // end main

    