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

Node* inorderBST(vector<int>& inorder, int start, int end) {

    if(start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node* root = new Node(inorder[mid]);

    root->left = inorderBST(inorder, start, mid-1);
    root->right = inorderBST(inorder, mid+1, end);

    return root;
}

Node* BalancedBST(Node* root) {

    vector<int> inorderVal;
    inorder(root, inorderVal);

    return inorderBST(inorderVal, 0, inorderVal.size()-1);
}

int main() {
    
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    Node* newRoot = BalancedBST(root);
    return 0;
}