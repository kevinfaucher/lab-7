#include "hashMap.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

hashMap::hashMap() {
    map = new *hashNode[mapSize];
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
    //there's nothing there (it's NULL), add the hashNode with the keyword and value
    if (mapSize == 0) {

        //Make a new Hashnode
        hashNode *temp = new hashNode(k,v);

        //add the hashNode with the keyword and value--based on index k from calc hash.
        //
        int index = calcHash(k);
        map[index] = temp;
        numKeys++;
    }

    //add to the list of values
    bool same = false;
    for (int i = 0; i < mapSize; i++) {
        if (map[i]->keyword == k) {
            map[i]->addValue(v);
            same = true;
        }

    }
    if (same == false) {
        int tempIndex = -1;
        int newIndex = -1;
        //
        
        //uses calchash to get index
        //check the index for NULL
        //if not collision
        //call dblhash
        //if null add key and the value
        while (map[v] != NULL || map->keyword == k) {
            tempIndex = calcHash(k); //This looks at a new index
            if (map[calcHash(k)]->keyword == v) {
                newIndex = tempIndex;
                map[newIndex]->addValue(k); //adding value to node
                numKeys++;
            }

        }

        if (newIndex == -1) {
            //Then you just add it on the end
            hashNode *temp = new hashNode(k, v);
            //add the hashNode with the keyword and value.
            int index = calcHash(k);
            map[index] = temp;
            numKeys++;
        }

    }
    float sev = 0.7; // value for checking if array is 70% full
    if ((float) (numKeys / mapSize) > sev) {
        reHash();
    }

}

int hashMap::getIndex(string k) {

}

int hashMap::calcHash(string k) {
    //return k % mapSize;
}

void hashMap::getClosestPrime() {

}

void hashMap::reHash() {

}

int hashMap::dblHash(int h, int i, string k) {

}

int hashMap::findKey(string k) {

}

void hashMap::printMap() {

}
