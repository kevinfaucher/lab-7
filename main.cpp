/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kevinf
 *
 * Created on May 10, 2017, 12:03 PM
 */

#include "makeSeuss.hpp"
#include "hashMap.hpp"
#include "hashNode.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

/*
 * 
 */
int main() {

    string g = "DrSeuss.txt";
    string h = "newfile.txt";  
    makeSeuss( g, h);
    return 0;
}

