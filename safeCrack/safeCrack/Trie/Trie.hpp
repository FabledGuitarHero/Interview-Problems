//
//  Trie.hpp
//  Trie
//
//  Created by Nate Henderson on 1/20/20.
//  Copyright © 2020 Nate Henderson. All rights reserved.
//

#ifndef Trie_hpp
#define Trie_hpp
#define CHAR_SIZE 126

#include <stdio.h>
#include <iostream>
#include <memory>

class TrieNode{
public:
    TrieNode();
    std::shared_ptr<TrieNode> character[CHAR_SIZE];
    bool isLeaf;
};

class Trie{
public:
    std::shared_ptr<TrieNode> root;
    int word_count;
    
    Trie();
    ~Trie();
    int i2c(char);
    int get_wordcount();
    void insert(std::string&);
    bool delete_word(std::string);
    bool part_delete(std::shared_ptr<TrieNode>&, std::string);
    bool search(std::string);
    bool isEmpty(std::shared_ptr<TrieNode>) const;
};

#endif /* Trie_hpp */
