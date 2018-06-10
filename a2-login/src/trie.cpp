#include "trie.hpp"

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
void search_rec(Trie* t, char c, vector<unsigned> p_row,const string& query, result* res);
unsigned triple_min(unsigned a, unsigned b, unsigned c);

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
result_t mysearch(const string& query,const Trie& root)
{
  vector<unsigned> row(query.size() + 1);
  //Initialize the array from 0 to the size of query
  for(unsigned i = 0; i < query.size(); ++i)
    row[i] = i;
  //Launch the recursive function of each child of the root
  result res;
  result cur;
  res.change(100000, nullptr);
  for(auto child: root.children)
  {
    cur.change(100000, nullptr);
    search_rec(child.second, child.first, row, query, &cur);
    if(cur.dist < res.dist)
      res.change(cur.dist, cur.word);
  }
  return result_t(*res.word, res.dist);
}
void search_rec(Trie* t, char c, vector<unsigned> p_row,const string& query, result* res)
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
  unsigned cur_dist = row[row.size() -1];
  if(cur_dist < res->dist && t->word != "")
    res->change(cur_dist, &t->word);

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
  current->word == "";
}
unsigned triple_min(unsigned a, unsigned b, unsigned c)
{
  if(b < a)
    a = b;
  if(c < a)
    a = c;
  return a;
}
