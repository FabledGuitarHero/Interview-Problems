//
//  main.cpp
//  domainForwarding
//
//  Created by Nate Henderson on 7/15/20.
//  Copyright © 2020 Nate Henderson. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

void print_this_thing(std::map<std::string, std::vector<std::string>> mp){
    for (auto i : mp){
        cout << i.first << " ";
        for (auto n : i.second){
            cout << n << " ";
        }
        cout << endl;
    }
}

std::vector<std::vector<std::string>> domainForwarding(std::vector<std::vector<std::string>> redirects) {
    std::map<std::string, std::vector<std::string>> d_red;
    std::map<std::string, std::vector<std::string>>::iterator it;
    std::vector<std::string>::iterator vit;
    
    
    for (auto arr : redirects){
        it = d_red.find(arr[1]);
        //Searches keys for destination domain
        //If it firnds the key, add to the back of the stack
        if (it != d_red.end()){
            cout << " here " << endl;
            it->second.push_back(arr[0]);
        }
        //If it reaches the end without finding a key,
        //  check each row for an existing entry for destination
        else if (d_red.size() > 1){
            it = d_red.begin();
            
            for (; it != d_red.end(); it++){
                vit = std::find(it->second.begin(), it->second.end(), arr[1]);
                if (vit != it->second.end()){
                    it->second.push_back(arr[0]);
                    break;
                }
            }
        }
        //Doesn't exist, add key/pair to map.
        else{
            std::vector<std::string> tmp = {arr[0]};
            d_red.insert(std::pair<std::string, std::vector<std::string>>(arr[1],tmp));
        }
    }
    
    //print_this_thing(d_red);
    
    std::vector<std::vector<std::string>> test;
    for (auto i : d_red){
        std::vector<std::string> tmp {i.first};
        tmp.insert(tmp.end(), i.second.begin(), i.second.end());
        test.push_back(tmp);
    }
    
    return test;
    
}


int main(int argc, const char * argv[]) {
    
    std::vector<std::vector<std::string>> arr = {{"godaddy.net","godaddy.com"},
                                                 {"godaddy.org","godaddycares.com"},
                                                 {"godady.com","godaddy.com"},
                                                 {"godaddy.ne","godaddy.net"}};
    
    std::vector<std::vector<std::string>> ret = domainForwarding(arr);
    for (auto i : ret){
        for (auto j  : i )
            cout << j << " ";
        cout << endl;
    }
    
    return 0;
}
