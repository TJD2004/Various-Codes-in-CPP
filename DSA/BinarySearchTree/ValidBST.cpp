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

bool isBST(Node* root, int min, int max) {

    if(root == NULL) {
        return true;
    }

    if(root->data <= min || root->data >= max) {
        return false;
    }

    bool left = isBST(root->left, min, root->data - 1);
    bool right = isBST(root->right, root->data + 1, max);
    return left && right;
}

bool validBST(Node* root) {
    return isBST(root, INT32_MIN, INT32_MAX);
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    // Check if the binary tree is a valid BST
    if (validBST(root)) {
        cout << "The binary tree is a valid BST." << endl;
    } else {
        cout << "The binary tree is not a valid BST." << endl;
    }

    return 0;
}
