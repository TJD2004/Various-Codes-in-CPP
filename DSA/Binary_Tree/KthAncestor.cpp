#include<iostream>
#include<queue>
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

Node* buildTree() {
    int data;
    cout << "Enter the data: ";
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    Node* root = new Node(data);

    cout << "Enter the data to insert in left of " << data << ": ";
    root->left = buildTree();
    cout << "Enter the data to insert in right of " << data << ": ";
    root->right = buildTree();

    return root;
}

Node* solve(Node* root, int node, int k) {

    if(root == NULL) {
        return NULL;
    }

    if(root->data == node) {
        return root;
    }

    Node* leftAns = solve(root->left, node, k);
    Node* rightAns = solve(root->right, node, k);

    if(leftAns != NULL && rightAns == NULL) {
        k--;
        if(k == 0) {
            k = INT32_MAX;
            return root;
        }
        return leftAns;
    }

    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k == 0) {
            k = INT32_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int KthAncestor(Node* root, int node, int k) {

    Node* ans = solve(root, node, k);
    if(ans == NULL || ans->data == node) 
        return -1;
    else 
        return ans->data;
}

int main() {

    Node* root = buildTree();
    int k = 2;
    int node = 4;
    
    int result = KthAncestor(root, node, k);

    cout << k << " Ancestor of " << node << " is " << result << endl;

    return 0;
}