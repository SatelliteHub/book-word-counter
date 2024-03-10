#include <iostream>
#include <fstream>
#include <string>
#include "node.hpp"

using namespace std;

// forward declarations
bool process_node(string new_word, node*& tree);
void process_word_pairs(string before, string new_word, node*& tree);
void temp(string new_word, node*& tree);
void search(string word, node *tree);
void print_word_pairs(string word, node *tree);


//*********************************//
//          MAIN FUNCTION          //
//*********************************//

int main() {
    node* root = nullptr; // start with an empty tree
    
    int wordcount = 0; // optional
    int individual_node_count = 0; // optional

    ifstream ifile;
    string file_name;

    bool file_found = false;
    bool ctrl_D = false;

    //********* SEARCH FILE *********//
    while (file_found == false) {
        cout << "Please enter the name of the book file:" << endl;
        getline(cin, file_name);
        ifile.open(file_name);

        if (ifile.is_open() == true)
            file_found = true;
        else
            cout << "An error occurred attempting to open the file \"" << file_name << "\"." << endl;
    }

    //********* COUNT TOTAL WORD *********//
    string t_word;
    string before;
    while (ifile >> t_word) {
        if (cin.fail() == false) {
            wordcount++;
            if (process_node(t_word, root))
                individual_node_count++;
            if (before != "")
                process_word_pairs(before, t_word, root);
            before = t_word;
        }
    }

    cout << "The file \"" << file_name << "\" contains " << wordcount << " words of which " << individual_node_count << " are distinct." << endl << "Please enter the word you wish to check:" << endl; 

    while (ctrl_D == false) {
        string check_word;
        cin >> check_word;
        if (cin.eof() == false) {
            search(check_word, root);
            cout << "Please enter the word you wish to check:" << endl;
        }
        if (cin.eof() == true){
            ctrl_D = true; 
            cout << "Goodbye" << endl;
        }
    }
  return 0;
}


//****************************************//
//           FUNCTION DEFINITION          //
//****************************************//

// Returns true if the word is new, false otherwise
bool process_node(string new_word, node*& tree) {
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

// Search the word requested 
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

