#include<iostream>
#include<vector>
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

class Info {
public:
    int size;
    int max;
    int min;
    bool isBST;
};  


Info solve(Node* root, int &ans) {

    if(root == NULL) 
        return {0, INT32_MIN, INT32_MAX, true};

    Info left = solve(root->left, ans);
    Info right = solve(root->right, ans);

    Info currNode;

    currNode.size = 1 + left.size + right.size;
    currNode.max = max(root->data, max(left.max, right.max));
    currNode.min = min(root->data, min(left.min, right.min));

    if(left.isBST && right.isBST && root->data > left.max && root->data < right.min) {
        currNode.isBST = true;
    } else {
        currNode.isBST = false;
    }

    if(currNode.isBST) {
        ans = max(ans, currNode.size);
    }    

    return currNode;
}


int largestBSTinBinaryTree(Node* root) {

    int maxSize = 0;
    Info temp = solve(root, maxSize);
    return maxSize;
}

int main() {

    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout << largestBSTinBinaryTree(root) << endl;

    return 0;
}