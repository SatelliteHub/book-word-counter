#include "process_node.hpp"

bool process_node(std::string new_word, node*& tree) {
    bool response;
    if (tree == nullptr) {
        tree = new node();
        tree->assign(new_word);
        response = true; // It is a new word
    } else {
        if (new_word == *tree) {
            tree->count++;
            response = false; // It is not a new word
        }
        else {
            if (new_word < *tree)
                response = process_node(new_word, tree->before);
            else
                response = process_node(new_word, tree->after);
        }
    }
    return response;
}
