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

int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->right;
    }

    return count;
}

Node* LinkedListToBST(Node* &head, int n) {

    if(n <= 0  || head == NULL) {
        return NULL;
    }

    Node* left = LinkedListToBST(head, n/2);

    Node* root = head;
    root->left = left;

    head = head->right;

    root->right = LinkedListToBST(head, n - n/2 - 1);

    return root;
} 

void inOrder(Node* root, vector<int> &in) { 
    if(root == NULL) {
        return;
    }

    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

int main() {

    Node* head = new Node(1);
    head->right = new Node(2);
    head->right->right = new Node(3);
    head->right->right->right = new Node(4);
    head->right->right->right->right = new Node(5);
    head->right->right->right->right->right = new Node(6);
    head->right->right->right->right->right->right = new Node(7);

    int n = countNodes(head);

    Node* root = LinkedListToBST(head, n);

    vector<int> in;
    inOrder(root, in);

    for(int i=0; i<in.size(); i++) {
        cout << in[i] << " ";
    }

    return 0;
}