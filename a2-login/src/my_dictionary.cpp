#include "my_dictionary.hpp"



void my_dictionary::init(const std::vector<std::string>& word_list)
{
  root = Trie();
  for (const string &k: word_list)
    root.insert(k);
}
void my_dictionary::insert(const std::string& w)
{
  root.insert(w);
}
result_t my_dictionary::search(const std::string& query) const
{
  return mysearch(query, root);
}
void my_dictionary::erase(const std::string& w)
{
  root.erase(w);
}
