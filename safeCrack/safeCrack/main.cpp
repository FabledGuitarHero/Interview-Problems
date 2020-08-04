//
//  main.cpp
//  safeCrack
//
//  Created by Nate Henderson on 7/27/20.
//  Copyright © 2020 Nate Henderson. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <random>

#include "Trie.hpp"

template <class T>
class Random{
    private:
        T generator;
    public:
        Random() : generator ((unsigned int)std::chrono::high_resolution_clock::now().time_since_epoch().count()){}
        
    int generate_integer(int min, int max){
        return (std::uniform_int_distribution<int>(min, max - 1)(generator));
    }
};

int init_key(int n){
    Random<std::minstd_rand> rand;
    int base = 1;
    for (int i = 1; i < n; i++)
        base *= 10;
    
    return rand.generate_integer(0, 9*base);
}

std::string init_num(unsigned long n){
    std::string r;
    for (int i = 0; i < n; i++){
        r += std::to_string(init_key(6));
    }
    
    return r;
}

int main(int argc, const char * argv[]) {
    
    /*
        1. Generate string of rando's
        2. Randomly generate key number
        3. Use Trie/BTree
        4. Substr of 4 numbers
           4a. Cast to int
           4b. Check Trie/BTree if used before
           4c. Compare to key
           4d. Insert into Trie/BTree
           4e. Repeat
     */
    
    std::shared_ptr<Trie> head(new Trie);
    
    bool found = false;
    int index = 0;
    int count = 0;
    int key = init_key(4);
    std::string num = init_num(10);
    std::string srch = num.substr(index, index+4);
    
    std::cout << "key: " << key << std::endl;
    std::cout << "number: " << num << std::endl;
    
    
    
    while (!found){
        std::cout << "Attempting: " << srch << std::endl;
        if (!head->search(srch)){
            if (stoi(srch) == key){
                std::cout << "found: " << srch << std::endl;
                found = true;
            }
            else
                head->insert(srch);
        }
        
        index++;
        srch = num.substr(index, 4);
        
        if(index+4 == num.length()){
            std::string tmp = init_num(10);
            num = srch + tmp;
            index = 0;
            count++;
        }
    }
    
    
    std::cout << "Finished with " << count << " iterations of new digits" << std::endl;
    return 0;
}
