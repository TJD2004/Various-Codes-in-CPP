#include<iostream>
#include<map>
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

Node* solve(int in[], int post[], int &postOrderIndex, int inorderStart, int inorderEnd, map<int,int> &nodeToIndex) {
    
    // Base condition
    if(inorderStart > inorderEnd) {
        return NULL;
    }

    // Get the current node from postorder array and move the index
    int element = post[postOrderIndex--];
    Node* root = new Node(element);

    // Find the index of this element in inorder array
    int position = nodeToIndex[element];

    // Recurse for right subtree first, then left subtree (since it's postorder)
    root->right = solve(in, post, postOrderIndex, position+1, inorderEnd, nodeToIndex);
    root->left = solve(in, post, postOrderIndex, inorderStart, position-1, nodeToIndex);

    return root;
}

Node* buildTree(int in[], int post[], int n) {

    int postOrderIndex = n - 1;  // Start from the last element of postorder
    map<int,int> nodeToIndex;    // Mapping to store element -> index of inorder traversal
    createMapping(in, nodeToIndex, n);
    Node* ans = solve(in, post, postOrderIndex, 0, n-1, nodeToIndex);
    return ans;
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {

    int inOrder[] = {4, 2, 5, 1, 6, 3, 7};  // Inorder traversal
    int postOrder[] = {4, 5, 2, 6, 7, 3, 1};  // Postorder traversal
    
    int n = sizeof(inOrder) / sizeof(inOrder[0]);
    
    // Build the tree
    Node* root = buildTree(inOrder, postOrder, n);
    
    // Output the inorder traversal of the constructed tree
    cout << "Inorder traversal of the constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
