#include "trie.hpp"
#include <atomic>
#include <chrono>
#include <tbb/tbb.h>
#include <mutex>

void search_rec(Trie* t, char c, vector<unsigned> p_row,const string& query, result* res);
unsigned triple_min(unsigned a, unsigned b, unsigned c);

std::atomic<unsigned> g_mini = 100000;

void Trie::insert(const string& word)
{
  Trie* current = this;
  for (unsigned i = 0; i < word.size(); ++i)
  {
    if (current->children.find(word[i]) == current->children.end())
    {
      current->children[word[i]] = new Trie();
    }
    current = current->children[word[i]];
  }
  current->word = word;
}
const Trie* Trie::basic_search(const string& query) const
{
  const Trie* current = this;
  for (unsigned i = 0; i < query.size(); ++i)
  {
    auto k = current->children.find(query[i]);
    if (k == current->children.end())
    {
      return nullptr;
    }
    current = k->second;
  }
  return current->word == query ? current : nullptr;

}
result_t Trie::mysearch(const string& query) const {
    g_mini = 10000;
    //Check if the word exist performence increase dependently on the kind of query
    /*
    const Trie* basic = basic_search(query);
    if(basic != nullptr)
      return result_t( basic->word, 0);
    */
    vector<unsigned> row(query.size() + 1);
    //Initialize the array from 0 to the size of query
    for (unsigned i = 0; i <= query.size(); ++i)
        row[i] = i;
    //Launch the recursive function of each child of the root
    /*result cur;
    cur.change(1000000, nullptr);*/
    result res;
    res.change(1000000, nullptr);
    unsigned i = 0;
    char *iterators = new char[28];
    result* results = new result[28];
    for (int it = 0; it < 28; ++it) {
        iterators[it] = '%';
        result cur;
        cur.change(1000000, nullptr);
        results[it] = cur;
    }
    unsigned count = 0;
    for (auto it = children.begin(); it != children.end(); ++it)
    {
        iterators[count] = it->first;
        count++;
    }
    auto max_th = 27;
    tbb::parallel_for(0, max_th, [&](size_t it) {//for(auto it = children.begin(); it != children.end(); ++it)
        if (iterators[it] == '%')
            return;
        auto cur = results[it];
        cur.change(100000, nullptr);
        search_rec(children.at(iterators[it]), iterators[it], row, query, &cur);
        ++i;
    });
    //std::cout << "searching " << query << " found: " << *res.word << " " << res.dist<<std::endl;
    unsigned min = 100;
    for (int it = 0; it < 28; ++it) {
        auto cur = results[it];
        if (cur.dist < min) {
            min = cur.dist;
            res = cur;
        }
    }
    delete[] iterators;
    //delete[] results;

    return result_t(*res.word, res.dist);
}
void Trie::search_rec(Trie* t, char c, vector<unsigned>& p_row,const string& query, result* res) const
{
  vector<unsigned> row(p_row.size());
  row[0] = p_row[0] + 1;
  unsigned insert_cost;
  unsigned replace_cost;
  unsigned delete_cost;
  for(unsigned i = 1; i < p_row.size(); ++i)
  {
    insert_cost = row[i-1] + 1;
    delete_cost = p_row[i] + 1;
    replace_cost = query[i-1] == c ? p_row[i-1] : p_row[i-1] + 1;
    row[i] = triple_min(insert_cost, replace_cost, delete_cost);
  }
  //get min row
  unsigned min = 10000;
  for(unsigned i = 1; i < p_row.size(); ++i)
  {
    if(row[i] < min)
      min = row[i];
  }
  unsigned cur_dist = row[row.size() - 1];
  bool changed = false;
  if(t->word != "" && g_mini.load() > cur_dist)
  {
    g_mini.exchange(cur_dist);
    changed = true;
    res->change(cur_dist, &t->word);
    }
  if(min >= g_mini.load() && !changed)
    return;
  if (!t->children.empty())
  {
    for (auto it = t->children.begin(); it != t->children.end(); ++it)
      search_rec(it->second, it->first, row, query, res);
  }
}
void Trie::erase(const string& w)
{
  Trie* current = this;
  for(char k: w)
  {
    if(current->children.find(k) == current->children.end())
      return;
    else
      current = current->children[k];
  }
  if (current->word != w)
    return;
  current->word = "";
}
inline
unsigned triple_min(unsigned a, unsigned b, unsigned c)
{
  if(b < a)
    a = b;
  if(c < a)
    a = c;
  return a;
}
