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

// Function to find the kth smallest element in the BST
int solve1(Node* root, int k, int &i) {
    if (root == NULL) {
        return -1;
    }

    int left = solve1(root->left, k, i);
    if (left != -1) {
        return left;
    }

    i++;
    if (i == k) {
        return root->data;
    }

    return solve1(root->right, k, i);
}


// Function to find the kth largest element in the BST
int solve2(Node* root, int k, int &i) {
    if (root == NULL) {
        return -1;
    }

    int right = solve2(root->right, k, i);
    if (right != -1) {
        return right;
    }

    i++;
    if (i == k) {
        return root->data;
    }

    return solve2(root->left, k, i);
}


int KthSmallest(Node* root, int k) {

    int i = 0;
    int ans = solve1(root, k, i);
    return ans;
}

int KthLargest(Node* root, int k) {

    int i = 0;
    int ans = solve2(root, k, i);
    return ans;
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}


int main() {

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    int k = 3;
    cout << "The " << k << "th smallest element in the BST is: " << KthSmallest(root, k) << endl;

    return 0;
}