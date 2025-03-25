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

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = NULL;
    }

    // Function to insert a node in the BST
    Node* insert(Node* root, int val) {
        // If the tree is empty, return a new node
        if (root == NULL) {
            return new Node(val);
        }

        // Otherwise, recur down the tree
        if (val < root->data) {
            root->left = insert(root->left, val);
        } 
        else if (val > root->data) {
            root->right = insert(root->right, val);
        }

        // return the (unchanged) node pointer
        return root;
    }

    // Function to delete a node from the BST
    Node* deleteNode(Node* root, int val) {
        // Base case: If the tree is empty
        if (root == NULL) {
            return root;
        }

        // Otherwise, recur down the tree
        if (val < root->data) {
            root->left = deleteNode(root->left, val);
        } 
        else if (val > root->data) {
            root->right = deleteNode(root->right, val);
        } 
        else {
            // Node to be deleted found

            // Node with only one child or no child
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } 
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }

    // Function to find the node with minimum value in the BST
    Node* minValueNode(Node* node) {
        Node* current = node;

        // loop down to find the leftmost leaf
        while (current && current->left != NULL) {
            current = current->left;
        }

        return current;
    }

    // Function to find the node with the maximum value in the BST
    Node* maxValueNode(Node* node) {
        Node* current = node;

        // Traverse the tree to the rightmost node
        while (current && current->right != NULL) {
            current = current->right;
        }

        return current;
    }


    // Function to search a node in the BST
    bool search(Node* root, int val) {
        // Base case: root is null or val is present at the root
        if (root == NULL) {
            return false;
        }
        if (root->data == val) {
            return true;
        }

        // Value is greater than root's data, search in the right subtree
        if (val > root->data) {
            return search(root->right, val);
        }

        // Value is smaller than root's data, search in the left subtree
        return search(root->left, val);
    }

    // Iterative function to search for a node in the BST
    bool search(Node* root, int val) {
        Node* current = root;
    
        // Traverse the tree iteratively
        while (current != NULL) {
            if (val == current->data) {
                return true; // Node found
            } else if (val < current->data) {
                current = current->left; // Move to left subtree
            } else {
                current = current->right; // Move to right subtree
            }
        }
    
        return false; // Node not found
    }

    // Function to print inorder traversal of the BST
    void inorder(Node* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Wrapper function to insert a node
    void insert(int val) {
        root = insert(root, val);
    }

    // Wrapper function to delete a node
    void deleteNode(int val) {
        root = deleteNode(root, val);
    }

    // Wrapper function to search a node
    bool search(int val) {
        return search(root, val);
    }

    // Wrapper function to print inorder traversal
    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Inserting nodes into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal of the BST: ";
    bst.inorder();  // Expected: 20 30 40 50 60 70 80
    cout << endl;

    // Searching for a node
    int valToSearch = 40;
    if (bst.search(valToSearch)) {
        cout << "Node " << valToSearch << " found in the tree." << endl;
    } else {
        cout << "Node " << valToSearch << " not found in the tree." << endl;
    }

    // Deleting a node
    int valToDelete = 20;
    cout << "Deleting node " << valToDelete << "..." << endl;
    bst.deleteNode(valToDelete);
    bst.inorder();  // Expected: 30 40 50 60 70 80
    cout << endl;

    return 0;
}
