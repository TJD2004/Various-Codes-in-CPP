#include<iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    } 
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0'); 
    }

    void insertUtil(TrieNode* node, string word) {
        if (word.length() == 0) {
            node->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if (node->children[index] != NULL) {
            child = node->children[index];
        } else {
            child = new TrieNode(word[0]);
            node->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* node, string word) {
        if (word.length() == 0) {
            return node->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child = node->children[index];

        if (child == NULL) {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    void removeUtil(TrieNode* node, string word) {
        if (word.length() == 0) {
            node->isTerminal = false;  // Just unmark the end of word
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child = node->children[index];

        if (child == NULL)
            return; // Word not found, nothing to remove

        removeUtil(child, word.substr(1));
    }

    void removeWord(string word) {
        removeUtil(root, word);
    }
};


int main() {
    Trie* t = new Trie();
    t->insertWord("hello");
    t->insertWord("hell");
    t->insertWord("heaven");
    t->insertWord("heavy");

    cout << "Searching for 'hello': " << (t->searchWord("hello") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'hell': " << (t->searchWord("hell") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'heaven': " << (t->searchWord("heaven") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'heavy': " << (t->searchWord("heavy") ? "Found" : "Not Found") << endl;

    t->removeWord("hello");
    cout << "After removing 'hello', searching for 'hello': " << (t->searchWord("hello") ? "Found" : "Not Found") << endl;

    return 0;
}