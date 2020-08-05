//
//  main.cpp
//  findSubarrayBySum
//
//  Created by Nate Henderson on 8/5/20.
//  Copyright © 2020 Nate Henderson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>

//Sliding window method O(n)
//Constraint: returns array index+1
std::vector<int> findSubarrayBySum(int sum, std::vector<int> a) {
    std::vector<int> vec{0,0};
    int total = 0;
    while (vec[0] <= a.size()-1){
        if(total == sum)
            return std::vector<int>{vec[0]+1, vec[1]};
        if (total < sum && vec[1] < a.size()+1){
            total += a[vec[1]];
            vec[1]++;
        }
        else{
            total -= a[vec[0]];
            vec[0]++;
        }
    }
    return std::vector<int> {-1};
}

void print_vect(std::vector<int> &vec){
    std::ostringstream ss;
    long length;
    
    ss << "[";
    for (auto i : vec){
        ss << i << ", ";
    }
    
    length = ss.str().length();
    std::cout << ss.str().substr(0, length-2) << "]" << std::endl;
}

int main(int argc, const char * argv[]) {
    std::vector<int> ans;
    
    std::vector<int> arr {4, 8, 9, 10, 3, 8};
    ans = findSubarrayBySum(21, arr);  // [1, 3]
    print_vect(ans);
    
    std::vector<int> arr2 {1, 2, 3, 1, 4, 5, 6, 7, 8, 9, 10};
    ans = findSubarrayBySum(15, arr2); // [2, 6]
    print_vect(ans);
    
    std::vector<int> arr3 {135, 101, 170, 125, 79, 159, 163, 65, 106, 146, 82, 28, 162, 92, 196, 143, 28, 37, 192, 5, 103, 154, 93, 183, 22, 117, 119, 96, 48, 127, 172, 139, 70, 113, 68, 100, 36, 95, 104, 12, 123, 134};
    ans = findSubarrayBySum(468, arr3); //[38, 42]
    print_vect(ans);
    
    std::vector<int> arr4 {142, 112, 54, 69, 148, 45, 63, 158, 38, 60, 124, 142, 130, 179, 117, 36, 191, 43, 89, 107, 41, 143, 65, 49, 47, 6, 91, 130, 171, 151, 7, 102, 194, 149, 30, 24, 85, 155, 157, 41, 167, 177, 132, 109, 145, 40, 27, 124, 138, 139, 119, 83, 130, 142, 34, 116, 40, 59, 105, 131, 178, 107, 74, 187, 22, 146, 125, 73, 71, 30, 178, 174, 98, 113};
    ans = findSubarrayBySum(665, arr4); // [-1]
    print_vect(ans);
    
    std::vector<int> arr5 {162, 37, 156, 168, 56, 175, 32, 53, 151, 151, 142, 125, 167, 31, 108, 192, 8, 138, 58, 88, 154, 184, 146, 110, 10, 159, 22, 189, 23, 147, 107, 31, 14, 169, 101, 192, 163, 56, 11, 160, 25, 138, 149, 84, 196, 42, 3, 151, 92, 37, 175, 21, 197, 22, 149, 200, 69, 85, 82, 135, 54, 200, 19, 139, 101, 189, 128, 68, 129, 94, 49, 84, 8, 22, 111, 18, 14, 115, 110, 17, 136, 52, 1, 50, 120, 157, 199};
    ans = findSubarrayBySum(1291, arr5); // [-1]
    print_vect(ans);
    
    std::vector<int> arr6 {26, 144, 125, 24, 173, 62, 182, 4, 33, 106, 194, 126, 32, 93, 143, 23, 87, 65, 101, 188, 161, 14, 175, 71, 171, 36, 34, 112, 161, 97, 68, 86, 151, 141, 95, 96, 25, 20, 126, 177, 95, 59, 103, 172, 67, 79, 194, 52, 85, 19, 65, 120, 153, 1, 88, 61, 127, 11, 158, 171, 116, 177, 28, 44, 159, 165, 110, 83, 87, 166, 88, 178, 75, 26, 28, 30, 129, 24, 121, 103, 163, 124, 197, 138, 62, 196, 126, 65, 61, 3, 117, 31, 127, 12, 172, 12, 148, 154, 121, 191};
    ans = findSubarrayBySum(528, arr6); // [2,6]
    print_vect(ans);
    
    
    return 0;
}
