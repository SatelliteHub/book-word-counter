#include "search.hpp"
#include <iostream>
#include "print_word_pairs.hpp"

using namespace std;

void search(string word, node *tree) {
    if (tree == nullptr) {
    cout << "The word \"" << word << "\" was not found." << endl;
  }
    else if (*tree == word) {
        cout << "Word pairs starting with \"" << word << "\" were ";
        if (tree->pairs == nullptr) {
            cout << "not found." << endl;
        }
        else {
            if (tree->count_pair == 1)
                cout << "found once." << endl;
            else if (tree->count_pair == 2)
                cout << "found twice." << endl;
            else
                cout << "found " << tree->count_pair << " times." << endl;
            print_word_pairs(word, tree->pairs);
        }
    }
    else {
        if (word < *tree)
            search(word, tree->before);
        else
            search(word, tree->after);
    }
}
