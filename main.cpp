#include <iostream>
#include <fstream>
#include <string>
#include "node.hpp"
#include "process_node.hpp"
#include "search.hpp"
#include "print_word_pairs.hpp"
#include "process_word_pairs.hpp"
#include "temp.hpp"

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
