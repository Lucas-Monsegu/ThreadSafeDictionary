#pragma once
#include "IDictionary.hpp"
#include <map>
#include <iostream>
#include <vector>
using namespace std;
struct result
{
  unsigned dist;
  string* word;
  void change(unsigned d, string *w)
  {
    dist = d;
    word = w;
  }
};

class Trie
{
  public:
    map<char, Trie*> children;
    string word;
  private:
    const Trie* basic_search(const string& query) const;
    void search_rec(Trie* t, char c, vector<unsigned>& p_row,const string& query, result* res) const;

  public:

    Trie()
    : children(map<char, Trie*>())
    {}

    void insert(const string& word);
    void erase(const string& w);
    result_t mysearch(const string& query) const;
};
