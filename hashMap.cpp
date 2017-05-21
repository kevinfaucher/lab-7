#include "hashMap.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

hashMap::hashMap() {
    *map = new hashNode[100];
    first = "";
    numKeys = 0;
    mapSize = 100;
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
    //there's nothing there (it's NULL), add the hashNode with the keyword and value 
    // if (mapSize == 0) {

    float sev = 0.7; // value for checking if array is 70% full
    if ((float) (numKeys / mapSize) > sev) {
        reHash();
    }
    if (numKeys == 0) {

        //Make a new Hashnode
        hashNode *temp = new hashNode(k, v);

        //add the hashNode with the keyword and value--based on index k from calc hash.
        //
        cout << "about to run calchash" << endl;
        int index = calcHash(k);
        cout << "calchash ran" << endl;
        map[index] = temp;
        cout << "added to the map" << endl;
        numKeys++;
        cout << "added to num keys" << endl;
    }

    //add to the list of values
    cout << "adding to the list of values" << endl;
    bool same = false;
    int x = findKey(k);
    if (x != -1) {
        map[x]->addValue(v);
        same = true;
    } else if (same == false) {
        int tempIndex = -1;
        int newIndex = -1;

        if (newIndex == -1) {
            //Then you just add it on the end
            hashNode *temp = new hashNode(k, v);
            //add the hashNode with the keyword and value.
            int index = calcHash(k);
            map[index] = temp;
            numKeys++;
        }

    }

    //RIGHT
    //uses calchash to get index
    //check the index for NULL
    //if not Null there is a collision
    //call dblhash


    int hashIndex = calcHash(k);

    if (map[hashIndex] == NULL) {
        //add the key and value
        //Make a new Hashnode
        hashNode *temp = new hashNode(k, v);

        //add the hashNode with the keyword and value--based on index k from calc hash.
        //
        int index = calcHash(k);
        map[index] = temp;
        numKeys++;
    } else if (map[hashIndex] != NULL)
        dblHash(k);


}


// uses calcHash and reHash to calculate and return
//the index of where the keyword k should be inserted into the map array

int hashMap::getIndex(string k) {
    float sev = 0.7; // value for checking if array is 70% full
    if ((float) (numKeys / mapSize) > sev) {
        reHash();
    } else {
        return calcHash(k);
    }
}

int hashMap::calcHash(string k) {
    //return k % mapSize;
    int sum = 0;

    for (unsigned int i = 0; i < k.size(); i++) {
        sum += k[i];
    }
    // i.e: string "abc" would have a value of 1+2+3=6 
    //strSum holds the sum of the chars of string k
    //this hash function calculates index by modding strSum by mapsize

    return sum % mapSize;
}


// I used a binary search on an array of prime
//numbers to find the closest prime to double the map Size, and then set mapSize to
//that new prime. You can include as one of the fields an array of prime numbers, or
//you can write a function that calculates the next prime number. Whichever you
//prefer.

void hashMap::getClosestPrime(int primeArr) {
    mapSize = mapSize * 2;
    //now we have to find the closest prime number to this result
    //and set mapSize equal to that
    int myPrime = -1;
    int i = 0;
    while (mapSize > myPrime) {
        myPrime = ++primeArr;
    }
    int higherInterval = mapSize - myPrime;
    int higherPrime = myPrime;
    myPrime = --primeArr;
    int lowerInterval = mapSize - myPrime;
    int lowerPrime = myPrime;

    if (higherInterval <= lowerInterval) {
        mapSize = higherPrime;
    } else {
        mapSize = lowerPrime;
    }


}


// when size of array is at 70%, double array size and rehash
//keys

void hashMap::reHash() {
    hashNode **dblMapArray1;
    *dblMapArray1 = new hashNode[mapSize * 2];

    for (int i = 0; i <= mapSize; i++) {
        dblMapArray1[i] = map[i];
    }
    delete [] map;
    map = dblMapArray1;
}

int hashMap::dblHash(string k) {
    int primeNum = 7; //Initializing a prime number less than the size of the map
    //lucky number 7--can't go wrong :)

    int sum = 0;
    for (unsigned int i = 0; i < k.size(); i++) {
        sum += k[i];
    }
    // i.e: string "abc" would have a value of 1+2+3=6 
    //strSum holds the sum of the chars of string k
    //this hash function calculates index by taking primNum and subtracting  strSum mod primeNum


    return primeNum - (sum % primeNum);
}

int hashMap::findKey(string k) {
    for (int i = 0; i < mapSize; i++) {
        if (map[i]->keyword == k) {
            return i;
        } else {
            return -1;
        }
    }
}

void hashMap::printMap() {
    for (int i = 0; i <= numKeys; i++) {
        cout << map[i]->keyword << " : " << map[i]->values << endl;
    }
}