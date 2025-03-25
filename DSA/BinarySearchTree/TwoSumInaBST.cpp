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

bool TwoSumInaBST(Node* root, int target) {

    vector<int> inorderVal;
    inorder(root, inorderVal);

    int i=0, j = inorderVal.size()-1;

    while(i<j) {
        if(inorderVal[i] + inorderVal[j] == target) {
            return true;
        } else if(inorderVal[i] + inorderVal[j] < target) {
            i++;
        } else {
            j--;
        }
    }
    return false;
}

int main() {

    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(2);

    int target = 24;

    if(TwoSumInaBST(root, target)) {
        cout << "Yes, there exists two elements in the BST whose sum is equal to " << target << endl;
    } else {
        cout << "No, there does not exist two elements in the BST whose sum is equal to " << target << endl;
    }

    return 0;
}