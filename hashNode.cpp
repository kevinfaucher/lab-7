#include "hashNode.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

hashNode::hashNode() {

    keyword = "";
    valuesSize = 0;
    values = new string[valuesSize];
    currSize = 0;
}

hashNode::hashNode(string s) {
    //1)init. keyword to s
    keyword = s;

    // 2) init. arraysize to 100
    //values[100]; 
    currSize = 0;
    valuesSize = 100;
    values = new string[valuesSize];

    //4) init. valuesSize to 100


    // 3) init. currSize to 0

}

hashNode::hashNode(string s, string v) {
    //increment the Array, and put in the new string
    //Need to increment the pointer and put in a string
    cout << "constructor 3 was called" << endl;
    cout << "this is k " << s << endl;
    keyword = s;

    cout << "created values array" << endl;
    currSize = 1;
    valuesSize = 100;
    values = new string[valuesSize];
    values[currSize] = v;
    cout << "constructor 3 was called and completed" << endl;
}

void hashNode::addValue(string v) {
    // adds a new value to the end of the values array,
    values[currSize] = v;

    //increases currSize,
    currSize++;

    //checks to make sure there’s more space, and, if not, calls
    //dblArray()
    if (currSize >= valuesSize) {
        dblArray();
    }
}
//creates a new array, double the length, and copies over the
//    values. Sets the values array to be the newly allocated array.
//    string getRandValue(); // returns a random string from the values array. If
//    there’s no values in the value array, then it returns an empty string.

void hashNode::dblArray() {
    string *dblArray = new string[valuesSize * 2]; //new array

    //Copying over the values
    for (int i = 0; i <= currSize; i++) {
        dblArray[i] = values[i];
    }
    //values = dblArray;

}


// returns a random string from the values array. If
// there’s no values in the value array, then it returns an empty string.

string hashNode::getRandValue() {

    //Special Case if currSize == 0;
    if (currSize == 0) {
        return "";
    }
    //Make a random variable between (0, currSize-1)
    int randomVar = 0 + (rand() % (currSize - 1));
    //return that string
    return values[randomVar];


}
