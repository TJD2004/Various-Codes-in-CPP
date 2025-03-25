#include<iostream>
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

Node* LCAinaBST(Node* root, Node* p, Node* q) {

    if(root == NULL) {
        return NULL;
    }

    if(root->data < p->data && root->data < q->data) {
        return LCAinaBST(root->right, p, q);
    }
    if(root->data > p->data && root->data > q->data) {
        return LCAinaBST(root->left, p, q);
    }

    return root;
}

int main() {

    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    Node* p = root->left->right->left;
    Node* q = root->left->right->right;

    Node* lca = LCAinaBST(root, p, q);
    cout << "Lowest Common Ancestor of " << p->data << " and " << q->data << " is " << lca->data << endl;

    return 0;
}