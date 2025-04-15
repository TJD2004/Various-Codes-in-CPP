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
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Node* root, vector<int>& in) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

void preorder(Node* root, vector<int>& in, int& index) {
    if (root == NULL) {
        return;
    }

    root->data = in[index++];
    preorder(root->left, in, index);
    preorder(root->right, in, index);
}

void BSTtoMinHeap(Node* root) {
    vector<int> inorderTraversal;
    inorder(root, inorderTraversal);
    int index = 0;
    preorder(root, inorderTraversal, index);
}

void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printPreorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout << "Inorder of the original BST: ";
    printInorder(root);
    cout << endl;

    BSTtoMinHeap(root);

    cout << "Inorder of the modified Min-Heap: ";
    printInorder(root);
    cout << endl;

    cout << "Preorder of the modified Min-Heap: ";
    printPreorder(root);
    cout << endl;

    return 0;
}
