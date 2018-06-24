#include "my_async_dictionary.hpp"

void my_async_dictionary::init(const std::vector<std::string>& word_list)
{
  root = Trie();
  for (const string &k: word_list)
    root.insert(k);
}
void my_async_dictionary::insert(const std::string& w)
{
  std::lock_guard<std::shared_mutex> lock(m);
  root.insert(w);
}
result_t my_async_dictionary::search(const std::string& query) const
{
  std::shared_lock<std::shared_mutex> lock(m);
  return root.mysearch(query);
}
void my_async_dictionary::erase(const std::string& w)
{
  std::lock_guard<std::shared_mutex> lock(m);
  root.erase(w);
}

