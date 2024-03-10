#include "temp.hpp"
#include "iostream"

using namespace std;

// Save the word temporarily with the previous word
void temp(string new_word, node*& tree) {
  if (tree == nullptr) {
    tree = new node();
    tree->assign(new_word);
  }
    else {
        if (*tree == new_word)
            tree->count++;
        else if (new_word < *tree)
            temp(new_word, tree->before);
        else
            temp(new_word, tree->after);
    }
}
