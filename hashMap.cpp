#include "hashMap.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;
/*
    hashNode **map;
    string first; // for first keyword for printing to a file
    int numKeys;
    int mapSize;
 */

// when creating the map, make sure you initialize the values to
// NULL so you know whether that index has a key in it or not already

hashMap::hashMap() {
    *map = new hashNode[101];
    first = "";
    numKeys = 0;
    mapSize = 101;

    for (int i = 0; i < mapSize; i++) {
        map[i] = NULL;
    }
}

//AddKeyValue
// adds a node to the map at the correct index based on the key string, and
//then inserts the value into the value field of the hashNode
// Must check to see whether there's already a node at that location. If
//there's nothing there (it's NULL), add the hashNode with the keyword and value.
// If the node has the same keyword, just add the value to the list of values.
//If the node has a different keyword, keep calculating a new hash index until
//either the keyword matches the node at that index's keyword, or until the
// map at that index is NULL, in which case you'll add the node there.
//This method also checks for load, and if the load is over 70%, it calls the
//reHash method to create a new longer map array and rehash the values

void hashMap::addKeyValue(string k, string v) {

    cout << "made it to addKeyValue" << endl;

    int index = getIndex(k);
    while (map[index] != NULL) {
        cout << "made it to addKeyValue while loop" << endl;
        // Case 1: the current key matches. In that case, add the value
        // to the existing hashnode and return.
        if (map[index]->keyword == k) {
            cout << "made it to addKeyValue if before addValue" << endl;
            map[index]->addValue(v);
             cout << "made it to addKeyValue if after addValue" << endl;
            return;
        } else {

            index = (index + dblHash(k)) % mapSize;
                cout << "made it to addKeyValue past else" << endl;
        }

        // Case 2: the current key is different. In that case, add the
        // double hash value to index (and mod mapSize) to test again!


    }
    // Make a new node, insert it at map[index].
    cout << "before third constructor" << endl;
    map[index] = new hashNode(k, v);
    cout << "after third constructor" << endl;
    numKeys++;
    cout << "made it out of addKeyValue" << endl;
}


// uses calcHash and reHash to calculate and return
//the index of where the keyword k should be inserted into the map array

int hashMap::getIndex(string k) {
    float sev = 0.7; // value for checking if array is 70% full
    if ((float) numKeys / mapSize > sev) {
        reHash();
    }
    return calcHash(k) % mapSize;

}

int hashMap::calcHash(string k) {
    //return k % mapSize;
    int sum = 0;

    for (unsigned int i = 0; i < k.size(); i++) {
        sum += k[i];
    }
    // this actually uses ascii now
    //strSum holds the sum of the chars of string k
    //this hash function calculates index by modding strSum by mapsize

    return sum;
}


//Instructions from my lab

// I used a binary search on an array of prime
//numbers to find the closest prime to double the map Size, and then set mapSize to
//that new prime. You can include as one of the fields an array of prime numbers, or
//you can write a function that calculates the next prime number. Whichever you
//prefer.

void hashMap::getClosestPrime() {
    cout << "made it to get closest prime" << endl;
    int number = mapSize + 1;
    while (true) {
        int i;
        for (i = 3; (i * i) <= number; i += 2) {
            if (number % i == 0) {
                break;
            }

        }
        if (i * i > number) {
            break;
        }

        number += 2;
    }
    mapSize = number;

}


// when size of array is at 70%, double array size and rehash
//keys

void hashMap::reHash() {

    // save the current mapSize
    int currMapSize = mapSize;
    // compute the new mapSize
    mapSize *= 2;
    getClosestPrime();
    cout << "made it past get ClosestPrime" << endl;
    // Make new table pointer refer to current map.
    hashNode **oldMap = map;

    // make new table with new mapSize, assign "map" to it.
    *map = new hashNode[mapSize];


    for (int i = 0; i < currMapSize; i++) {
        cout << "made it past first for loop" << endl;
        if (oldMap[i] != NULL) {
            for (int j = 0; j < oldMap[i]->currSize; j++) {
                cout << "second for loop" << endl;
                addKeyValue(oldMap[i]->keyword, oldMap[i]->values[j]);
                cout << "made it past add key" << endl;

            }
            cout << "made it past both for loops" << endl;
            delete [] oldMap[i]->values;
            delete oldMap[i];
            cout << "made it past delete" << endl;
        }
        

        // delete the old table.

    }
    delete [] oldMap;
    cout << " made it out of rehash" << endl;
}

int hashMap::dblHash(string k) {
    return 7 - calcHash(k) % 7;
}

int hashMap::findKey(string k) {
    int index = getIndex(k);
    while (map[index] != NULL) {
        if (map[index]->keyword == k) {
            return index;
        } else {
            index = (index + dblHash(k)) % mapSize;
        }
    }
    return -1;

}

void hashMap::printMap() {
    for (int i = 0; i <= numKeys; i++) {
        cout << map[i]->keyword << " : " << map[i]->values << endl;
    }
}