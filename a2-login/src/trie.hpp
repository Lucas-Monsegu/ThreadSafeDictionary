#pragma once
#include "IDictionary.hpp"
#include <map>
#include <iostream>
#include <vector>
using namespace std;

class Trie
{
  public:
    map<char, Trie*> children;
    string word;


    Trie()
    : children(map<char, Trie*>())
    {}

    void insert(const string& word);
    void erase(const string& w);
};
result_t mysearch(const string& query, const Trie&);
