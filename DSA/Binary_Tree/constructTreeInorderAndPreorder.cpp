#include<iostream>
#include<map>
#include<unordered_map>
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

int createMapping(int in[], map<int,int> &nodeToIndex, int n) {
    for(int i = 0; i < n; i++) {
        nodeToIndex[in[i]] = i;
    }
    return 0;
}

Node* solve(int in[], int pre[], int index, int &preOrderIndex, int inoderStart, int inorderEnd, int n, map<int,int> nodeToIndex) {
    
    if(index >= n || inoderStart > inorderEnd) {
        return NULL;
    }

    int element = pre[preOrderIndex++];
    Node* root = new Node(element);
    int position = nodeToIndex[element];

    root->left = solve(in, pre, index, preOrderIndex, inoderStart, position-1, n, nodeToIndex);
    root->right = solve(in, pre, index, preOrderIndex, position+1, inorderEnd, n, nodeToIndex);

    return root;
}

Node* buildTree(int in[], int pre[], int n) {

    int preOrderIndex = 0;
    map<int,int> nodeToIndex;
    createMapping(in, nodeToIndex, n);
    Node* ans = solve(in, pre, 0, preOrderIndex, 0, n-1, n, nodeToIndex);
    return ans;
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {

    int inOrder[] = {4, 2, 5, 1, 6, 3, 7};
    int preOrder[] = {1, 2, 4, 5, 3, 6, 7};
    
    int n = sizeof(inOrder) / sizeof(inOrder[0]);
    
    // Build the tree
    Node* root = buildTree(inOrder, preOrder, n);
    
    // Output the inorder traversal of the constructed tree
    cout << "Inorder traversal of the constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
