#include<iostream>
#include<queue>
#include<vector>  
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int NodeCount(Node* root) {
    if(root == NULL) {
        return 0;
    }
    return 1 + NodeCount(root->left) + NodeCount(root->right);
}

bool isCBT(Node* root, int index, int totalCount) {
    if(root == NULL) {
        return true;
    }

    if(index >= totalCount) {
        return false;
    }

    return isCBT(root->left, 2*index + 1, totalCount) && isCBT(root->right, 2*index + 2, totalCount);
}


bool isMaxOrder(Node* root) {
    if(root->left == NULL && root->right == NULL) {
        return true;
    }

    if(root->right == NULL) {
        return (root->data > root->left->data);
    }
    else {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && (root->data > root->left->data) && (root->data > root->right->data));
    }
}



bool isHeap(Node* root) {
    
    int index = 0;
    int totalCount = NodeCount(root);
    if(isCBT(root, index, totalCount) && isMaxOrder(root)) {
        return true;
    }
    return false;
}

int main() {
    Node* root = new Node(90);
    root->left = new Node(80);
    root->right = new Node(70);
    root->left->left = new Node(60);
    root->left->right = new Node(50);
    root->right->left = new Node(40);
    root->right->right = new Node(30);

    if(isHeap(root)) {
        cout << "The binary tree is a heap." << endl;
    } else {
        cout << "The binary tree is not a heap." << endl;
    }

    return 0;
}