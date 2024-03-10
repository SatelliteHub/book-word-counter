#include "print_word_pairs.hpp"
#include <iostream>

using namespace std;

// Print the word pairs in alphabetical order
void print_word_pairs(string word, node *tree){
    if (tree != nullptr) {
        print_word_pairs(word, tree->before);
        if (tree->count == 1)
            cout << "\"" << word << " " << *tree <<"\" was found once." << endl;
        else if (tree->count == 2)
            cout << "\"" << word << " " << *tree <<"\" was found twice." << endl;
        else
            cout << "\"" << word << " " << *tree <<"\" was found " << tree->count << " times." << endl;
        print_word_pairs(word, tree->after);
    }
}
