#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "trie.h"


int main() {
    using namespace std;

    // input
    string input_string;
    getline(cin, input_string);

    vector<string> input;
    stringstream ss(input_string);
    string line;

    while (getline(ss, line, ' ')) {
        input.push_back(line);
    }

    // open file
    ifstream dict; 
    dict.open(input[0]);

    // insert dict in trie
    Trie trie;
    string word = "";
    int count_len = 0;
    int i;

    while (getline(dict, line, '\n')) {
        i = 1;
        word = "";

        while (true) {
            if (line[i] == ']')
                break;

            word += line[i];
            i++;
        }
        
        trie.insert(word, count_len, line.length());
        count_len += line.length() + 1;
    }

    // search for words
    int* searchResult;
    i = 1;

    while (true) {
        word = input[i];
        if (word.compare("0") == 0)
            break;
        i++;
        
        searchResult = trie.search(word);
        int found = searchResult[0];
        int pos = searchResult[1];
        int len = searchResult[2];
        int sufixes = searchResult[3];

        if (found) {
            if (sufixes)
                cout << word << " is prefix of " << sufixes << " words" << "\n";
            else 
                cout << word << " is prefix of 1 words" << "\n";
            cout << word << " is at " << "(" << pos << "," << len << ")" << "\n";
        } else {
            if (sufixes)
                cout << word << " is prefix of " << sufixes << " words" << "\n";
            else 
                cout << word << " is not prefix" << "\n";
        }
    }

    return 0;
}
