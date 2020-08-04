//
//  Trie.cpp
//  Trie
//
//  Created by Nate Henderson on 1/20/20.
//  Copyright © 2020 Nate Henderson. All rights reserved.
//

#include "Trie.hpp"

TrieNode::TrieNode(){
    
    for (int i = 0; i < CHAR_SIZE; i++){
        character[i] = std::shared_ptr<TrieNode>();
    }
    this -> isLeaf = false;
}


Trie::Trie(){
    root = std::shared_ptr<TrieNode>(new TrieNode());
    word_count = 0;
}
Trie::~Trie(){
    
}

int Trie::i2c(char c)
{
    return static_cast<int>(c - 'a');
}

void Trie::insert(std::string& key){
    std::shared_ptr<TrieNode> curr = this->root;
    
    for (int i = 0; i < key.size(); i++){
        if(curr->character[key[i]] == std::shared_ptr<TrieNode>(nullptr)){
            curr->character[key[i]] = std::shared_ptr<TrieNode>(new TrieNode());
        }
        
        curr = curr->character[key[i]];
    }
    curr->isLeaf = true;
    word_count++;
    
}

int Trie::get_wordcount(){ return word_count; }


bool Trie::search(std::string key){
    
    std::shared_ptr<TrieNode> curr = root;
    if (curr == std::shared_ptr<TrieNode>(nullptr))
        return false;

    for (int i = 0; i < key.length(); i++){
        curr = curr->character[key[i]];
        if (curr == nullptr)
            return false;
    }
    
    return curr->isLeaf;
}

bool Trie::delete_word(std::string key){
    if(part_delete(root, key))
        return true;
    return false;
}

bool Trie::part_delete(std::shared_ptr<TrieNode>& curr, std::string key){
    if (curr == nullptr){
        return false;
    }
    
    if(key.length() == 0){
        if(curr->isLeaf == true){
            curr->isLeaf = false;
            return true;
        }
        return false;
    }
    
    std::string part = key.substr(1);
    
    if(part_delete(curr->character[key[0]], part)){
        if(isEmpty(curr->character[key[0]])){
            curr->character[key[0]].reset();
            curr->character[key[0]] = nullptr;
            return true;
        }
        else
            return true;
    }
    else
        return false;
    
    return false;
}

bool Trie::isEmpty(std::shared_ptr<TrieNode> curr) const {
    for (int i = 0; i < CHAR_SIZE; i++){
        if(curr->character[i] != nullptr || curr->isLeaf == true){
            return true;
        }
    }
    return false;
}

