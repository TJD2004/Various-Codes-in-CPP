#include <iostream>
#include <queue>
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
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    Node* root = new Node(data);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

Node* LCA(Node* root, int n1, int n2) {

    if(root == NULL) {
        return NULL;
    }

    // If the root is one of n1 or n2, then root is LCA
    if(root->data == n1 || root->data == n2) {
        return root;
    }

    // Check in left and right subtree
    Node* leftAns = LCA(root->left, n1, n2);
    Node* rightAns = LCA(root->right, n1, n2);

    // If both subtrees have one key, then root is LCA
    if(leftAns != NULL && rightAns != NULL) {
        return root;
    }

    // Otherwise, return non-null child (if any)
    return (leftAns != NULL) ? leftAns : rightAns;
}

int main() {
    int T;
    cin >> T; // Number of test cases
    
    while(T--) {
        Node* root = buildTree(); // Build the tree
        
        int n1, n2;
        cin >> n1 >> n2; // Read the two nodes for which LCA is to be found
        
        Node* lcaNode = LCA(root, n1, n2);
        
        // Print the result
        if(lcaNode != NULL) { 
            cout << lcaNode->data << endl;
        } else {
            cout << "LCA not found" << endl;
        }
    }
    
    return 0;
}

/* Sample Input:
1
1
2
4
-1
-1
5
-1
-1
3
6
-1
-1
7
-1
-1
4 7

Sample Output:
3
*/
