#pragma once
#include "IDictionary.hpp"
#include "trie.hpp"
#include <set>
#include <mutex>
#include <vector>

class my_dictionary : public IDictionary
{
protected:
  Trie root;
public:
  my_dictionary() = default;

  void init(const std::vector<std::string>& word_list) final;


  result_t      search(const std::string& w) const final;
  void          insert(const std::string& w) final;
  void          erase(const std::string& w) final;
};

