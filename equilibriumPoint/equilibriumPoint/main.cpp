//
//  main.cpp
//  equilibriumPoint
//
//  Created by Nate Henderson on 8/4/20.
//  Copyright © 2020 Nate Henderson. All rights reserved.
//

#include <iostream>
#include <vector>


int equilibriumPoint(std::vector<int> arr) {
    int m, l, r;
    m = l = r =  0;
    
    //Add up all elements
    for (auto i : arr)
        r+= i;
    //If arr size or sum == 1, return index 1
    if(arr.size() == 1 || r == 1)
        return 1;
    
    //Iterate array, subtracting left index and middle from sum
    while (m < arr.size()-1){
        l += arr[m];
        m++;
        if(l == (r-(l+arr[m])))
            return m+1;
    }
    return -1;
}


int main(int argc, const char * argv[]) {
    std::vector<int> arr {10, 5, 3, 5, 2, 2, 6, 8};
    std::vector<int> arr2 {1, 3, 5, 2, 3};
    std::vector<int> arr3 {24, 5, 17, 8, 15, 11, 21, 13, 23, 39, 30, 4, 14, 10, 8, 39, 20, 15, 3, 4, 16, 9, 19, 39, 34, 25, 29, 21, 31, 3, 21, 2, 9, 22, 31, 7, 21, 4, 30, 23, 5, 36, 3};
    std::vector<int> arr4 {1, -5, 2, 3};
    std::vector<int> arr5 {2, 3, -5, 100};
    std::vector<int> arr6 {1};
    
    std::cout << equilibriumPoint(arr) << std::endl;
    std::cout << equilibriumPoint(arr2) << std::endl;
    std::cout << equilibriumPoint(arr3) << std::endl;
    std::cout << equilibriumPoint(arr4) << std::endl;
    std::cout << equilibriumPoint(arr5) << std::endl;
    std::cout << equilibriumPoint(arr6) << std::endl;
    
    return 0;
}
