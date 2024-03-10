#pragma once
#include <string>

class node : public std::string {
  public:
  node();
  int count_pair; // number of word pairs of a word
  int count; // number of occurrences
  // "before" points to the subtree of words that come
  // before this word in alphabetical order
  node *before;
  // "after" points to the subtree of words that come
  // after this word in alphabetical order, duh.
  node *after;
  node *pairs; // link word pairs and word
};
