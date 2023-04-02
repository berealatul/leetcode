//incomplete

#pragma once
#include <string>
using namespace std;


class WordDictionary {
    struct Node {
        string word;
        Node* next;
        Node(string val) : word(val), next(nullptr) {}
    };
    vector<vector<Node*>> dictionary;
public:
    WordDictionary() {
        const int TOTAL_ALPHABET = 26;
        dictionary.resize(TOTAL_ALPHABET);
    }

    void addWord(string word) {

    }

    bool search(string word) {

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */