#ifndef TRIE_H
#define TRIE_H

#include <string>


class Trie {
 public:
    Trie();
    ~Trie();

    void insert(std::string data, int pos, int len);
    int* search(std::string data);

 private:
    struct Node {
        Node(int p, int l) {
            len = l;
            pos = p;
            for (int i = 0; i < 26; i++)
                children[i] = NULL;
        }

        Node* children[26];
        bool isEndOfWord{false};
        int pos;
        int len;
        int suffixes = 0;
    };

    void destructorAux(Node* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != NULL)
                destructorAux(node->children[i]);
        }

        delete node;
    }

    Node* root{nullptr};
};

Trie::Trie() {
    root = new Node(0, 0);
}

Trie::~Trie() {
    destructorAux(root); 
}

void Trie::insert(std::string data, int pos, int len) {
    Node* p = root;
    int index;

    for (int i = 0; i < static_cast<int>(data.length()); i++) {
        index = data[i] - 'a';
        if (i < static_cast<int>(data.length()) - 1) {
            if (p->children[index] == NULL)
                p->children[index] = new Node(0, 0);
        } else 
            if (p->children[index] == NULL)
                p->children[index] = new Node(pos, len);

        p = p->children[index];
        p->suffixes++;
    }

    p->isEndOfWord = true;
}

int* Trie::search(std::string data) {
    Node* p = root;
    int index, count;
    int* return_val = new int[4];

    for (int i = 0; i < static_cast<int>(data.length()); i++) {
        index = data[i] - 'a';
        if (p->children[index] != NULL) {
            p = p->children[index];
            count++;
        }
    }

    return_val[0] = (static_cast<int>(data.length()) != count) ? 0 : static_cast<int>(p->isEndOfWord);
    return_val[1] = p->pos;
    return_val[2] = p->len;
    return_val[3] = (static_cast<int>(data.length()) != count) ? 0 : p->suffixes;

    return return_val;
}

#endif
