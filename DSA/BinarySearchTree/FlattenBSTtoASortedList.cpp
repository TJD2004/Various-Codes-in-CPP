#include<iostream>
#include<vector>
using namespace std;

class Node {
public: 
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};  

void inorder(Node* root, vector<int>& in) {
    if(root == NULL) {
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

Node* FlattenBSTtoASortedList(Node* root) {

    vector<int> inorderVal;
    inorder(root, inorderVal);

    Node* newRoot = new Node(inorderVal[0]);
    Node* curr = newRoot;

    for(int i=1; i<inorderVal.size(); i++) {
        
        Node* temp = new Node(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = curr->right = NULL;
    return newRoot;
}

int main() {

    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    Node* newRoot = FlattenBSTtoASortedList(root);

    while(newRoot != NULL) {
        cout << newRoot->data << " ";
        newRoot = newRoot->right;
    }

    return 0;
}