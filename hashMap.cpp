#include "hashMap.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

hashMap::hashMap() {
    map = NULL;
    first = NULL;
    numKeys = NULL;
    mapSize = NULL;
}

//AddKeyValue

void hashMap::addKeyValue(string k, string v) {
    //there's nothing there (it's NULL), add the hashNode with the keyword and value
    if (map[v] == NULL) {

        //Make a new Hashnode
        hashNode temp = new hashNode(k, v);

        //add the hashNode with the keyword and value.
        (map + 1) = temp;
        numKeys++;
    }
    bool same = false;
    for (int i = 0; i <= mapSize; i++) {
        if (map[i]->keyword == v) {
            map[i]->addValue(k);
            same = true;
        }

    }
    if (same == false) {
        int tempIndex = -1;
        int newIndex = -1;
        while (map[v] != NULL || map->keyword == v) {
            tempIndex = calcHash(k); //This looks at a new index
            if (map[calcHash(k)]->keyword == v) {
                newIndex = tempIndex;
                map[newIndex]->addValue(k); //adding value to node
                numKeys++;
            }

        }

        if (newIndex == -1) {
            //Then you just add it on the end
            hashNode temp = new hashNode(k, v);
            //add the hashNode with the keyword and value.
            (map + 1) = temp;
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
