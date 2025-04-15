#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childCount = 0;
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

        int index = word[0] - 'a';
        TrieNode* child;

        if (node->children[index] != NULL) {
            child = node->children[index];
        } else {
            child = new TrieNode(word[0]);
            node->childCount++; 
            node->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        insertUtil(root, word);
    }

    void printSugestion(TrieNode* curr, vector<string>& temp, string prefix) {
        if(curr->isTerminal) 
            temp.push_back(prefix);

        for(char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr->children[ch - 'a'];
            if(next != NULL) {
                prefix.push_back(ch);
                printSugestion(next, temp, prefix);
                prefix.pop_back(); 
            }
        }
    }

    vector<vector<string>> getSugestions(string &str) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for(int i = 0; i < str.length(); i++) {
            char lastch = tolower(str[i]);
            prefix.push_back(lastch);

            TrieNode* curr = prev->children[lastch - 'a'];
            if(curr == NULL) {
                break;
            }

            vector<string> temp;
            printSugestion(curr, temp, prefix);

            output.push_back(temp);
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phonedirectry(vector<string> &contactList, string query) {
    Trie* t = new Trie;
    for(int i = 0; i < contactList.size(); i++) {
        t->insertWord(contactList[i]);
    }
    return t->getSugestions(query);
}

int main() {
    vector<string> contacts = {"Alice", "Ali", "Bob", "Alfred", "Bobby"};
    string query = "Al";

    vector<vector<string>> result = phonedirectry(contacts, query);

    for(int i = 0; i < result.size(); i++) {
        cout << "Suggestions for prefix '" << query.substr(0, i+1) << "': ";
        for(const string& s : result[i]) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}