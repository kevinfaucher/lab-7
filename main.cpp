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
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

/*
 * 
 */
int main() {

    string f1 = "DrSeuss.txt";
    string f2 = "NewBook.txt";  
    makeSeuss makeSeuss(f1, f2);
    
    return 0;
}

