//
//  main.cpp
//  isTreeSymetic
//
//  Created by Nate Henderson on 8/26/20.
//  Copyright © 2020 Nate Henderson. All rights reserved.
//

#include <iostream>
#include <vector>

template<typename T>
struct Tree {
    Tree() : value(NULL), left(nullptr), right(nullptr){}
    Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
    T value;
    Tree *left;
    Tree *right;
};

template<typename T>
Tree<T>* set_tree(const std::vector<T> &heap, Tree<T> *t, int index){

    if(index >= heap.size())
        return nullptr;
    
    Tree<T> *node = new Tree<T>(heap.at(index));
    node->left = set_tree(heap, node->left, (index*2)+1);
    node->right = set_tree(heap, node->right, (index*2)+2);
    
    return node;
}

template<typename T>
bool m(Tree<T> *l, Tree<T> *r){
    
    if(!l  &&  !r)
        return 1;
        
    if(l && r && l->value == r ->value)
        return m(l->left, r->right) && m(l->right, r->left);
    
    return 0;
}

int main(int argc, const char * argv[]) {
    std::vector<int> v1 {1,2,2,3,4,4,3};
    Tree<int> *t = new Tree<int>();
    t = set_tree(v1, t, 0);
    std::cout << m(t, t) << std::endl;  //True
    
    std::vector<int> v2 {1,2,3,2,3};
    Tree<int> *t2 = new Tree<int>();
    t2 = set_tree(v2, t2, 0);
    std::cout << m(t2,t2) << std::endl;  //Feals
    
    Tree<int> *t3 = new Tree<int>();
    std::cout << m(t3, t3) << std::endl; //True

    
    return 0;
}
