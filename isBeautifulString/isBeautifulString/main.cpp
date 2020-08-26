//
//  main.cpp
//  isBeautifulString
//
//  Created by Nate Henderson on 8/26/20.
//  Copyright © 2020 Nate Henderson. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool isBeautifulString(string s) {
    int loc = 0;
    vector<int> c (26);
    
    //Counts the number of occurances of character in string
    // using a vector to keep track of incriments.
    for (auto n : s)
        c[(n-96)-1]++;
    
    //Iterate through vector,
    //  If character count is greater than previous,
    //  return false.
    while(loc < 26){
        if(loc >= 1 && c[loc] > c[loc-1])
            return 0;
        loc++;
    }
    
    return 1;
}

int main(int argc, const char * argv[]) {
    string s1 = "bbbaacdafe";
    cout << isBeautifulString(s1) << endl;  //True
    
    string s2 = "aabbb";
    cout << isBeautifulString(s2) << endl;  //False
    
    string s3 = "bbc";
    cout << isBeautifulString(s3) << endl;  //False
    
    string s4 = "bbbaa";
    cout << isBeautifulString(s4) << endl;  //False
    
    string s5 = "abcdefghijklmnopqrstuvwxyzz";
    cout << isBeautifulString(s5) << endl;  //False
    
    string s6 = "abcdefghijklmnopqrstuvwxyz";
    cout << isBeautifulString(s6) << endl;  //True
    
    string s7 = "abcdefghijklmnopqrstuvwxyzqwertuiopasdfghjklxcvbnm";
    cout << isBeautifulString(s7) << endl; //True
    
    return 0;
}
