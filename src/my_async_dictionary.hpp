#pragma once
#include "IDictionary.hpp"
#include "trie.hpp"
#include <set>
#include <shared_mutex>
#include <vector>

class my_async_dictionary : public IDictionary
{
protected:
  Trie root;
  mutable std::shared_mutex m;
public:
  my_async_dictionary() = default;

  void init(const std::vector<std::string>& word_list) final;


  result_t      search(const std::string& w) const final;
  void          insert(const std::string& w) final;
  void          erase(const std::string& w) final;
};


