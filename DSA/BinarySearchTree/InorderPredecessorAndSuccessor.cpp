#include<iostream>
using namespace std;

class Node {     
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


pair<int,int> predecessorSuccessor(Node* root, int key) {

    Node* temp = root;
    int pred = -1;
    int succ = -1;

    while(temp->data != key) {
        if(temp->data > key) {
            succ = temp->data;
            temp = temp->left;
        } else {
            pred = temp->data;
            temp = temp->right;
        }
    }

    Node* leftTree = temp->left;
    while(leftTree != NULL) {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    Node* rightTree = temp->right;
    while(rightTree != NULL) {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int,int> res = make_pair(pred,succ);
    return res;
}

int main() {

    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int key = 65;
    pair<int,int> res = predecessorSuccessor(root, key);
    cout << "Predecessor: " << res.first << endl;
    cout << "Successor: " << res.second << endl;

    return 0;
}