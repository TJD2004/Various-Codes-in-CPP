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


void convertIntoSortedDLL(Node* root, Node* &head) {
    
    if(root == NULL) {
        return;
    }

    convertIntoSortedDLL(root->left, head);

    if(head == NULL) 
        head ->left = root;  
    
    head = root;

    convertIntoSortedDLL(root->right, head);
}

int inOderTraversal(Node* root) {
    if(root == NULL) {
        return 0;
    }

    inOderTraversal(root->left);
    cout << root->data << " ";
    inOderTraversal(root->right);
}

int main() {

    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    Node* head = NULL;
    convertIntoSortedDLL(root, head);

    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }

    return 0;
}   