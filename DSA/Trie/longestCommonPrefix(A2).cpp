#include<iostream>
#include<vector>
#include<string>
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

        int index = word[0] - 'A';
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
        insertUtil(root, word);
    }

    void LCP(string str, string &ans) {
        TrieNode* node = root;

        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];

            if (node->childCount == 1 && !node->isTerminal) {
                ans.push_back(ch);
                int index = ch - 'A';  
                node = node->children[index];
            } else {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n) {
    Trie *t = new Trie(); 
    for (int i = 0; i < n; i++) {
        t->insertWord(arr[i]);
    }

    string first = arr[0];  
    string ans = "";

    t->LCP(first, ans);  
    return ans;
}

int main() {
    vector<string> arr = {"flower", "flow", "flight"};
    int n = arr.size();
    string result = longestCommonPrefix(arr, n);
    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}