#include "hashNode.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

hashNode::hashNode() {

    keyword = "";
    values = NULL;
    valuesSize = 0;
    //currSize = 0;
}

hashNode::hashNode(string s) {
    //1)init. keyword to s
    keyword = s;

    // 2) init. arraysize to 100
    //values[100]; 
    values = new string[100];

    //4) init. valuesSize to 100
    valuesSize = 100;

    // 3) init. currSize to 0
    currSize = 0;
}

hashNode::hashNode(string s, string v) {
    //increment the Array, and put in the new string
    (values + 1) = v;

    //Update currSize to 1
    currSize = 1;
}

void hashNode::addValue(string v) {
    // adds a new value to the end of the values array,
    (values + 1) = v;

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
    int *dblArray = new int[valuesSize * 2]; //new array

    //Copying over the values
    for (int i = 0; i <= currSize; i++) {
        dblArray[i] = values[i];
    }
    values = dblArray;

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
