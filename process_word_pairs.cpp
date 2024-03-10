#include "process_word_pairs.hpp"
#include "temp.hpp"
#include <iostream>

using namespace std;

// Find the word before in the tree
void process_word_pairs(string before, string new_word, node*& tree) {
    if (*tree != before) {
        if (before < *tree)
            process_word_pairs(before, new_word, tree->before);
        else
            process_word_pairs(before, new_word, tree->after);
    }
    else {
        tree->count_pair++;
        temp(new_word, tree->pairs);
    }
}
