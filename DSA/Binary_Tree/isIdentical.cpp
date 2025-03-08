#include<iostream>
using namespace std;

class Node {
    public :
        int data;
        Node *left;
        Node *right;

        Node(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
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

bool isIdentical(Node *r1, Node *r2) {
    
    if(r1 == NULL && r2 == NULL) {
        return true;
    }

    if(r1 == NULL && r2 != NULL) {
        return false;
    }

    if(r1 != NULL && r2 == NULL) {
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool val = r1-> data == r2->data;

    if(left && right && val) {
        return true;
    }
    else {
        return false;
    }
}

int main() {

    Node* root1 = NULL;
    Node* root2 = NULL;

    // Build the tree (User Input Required)
    root1 = buildTree();
    cout << endl;

    root2 = buildTree();
    cout << endl;

    if(isIdentical(root1,root2)) {
        cout <<"Tree is Identical" << endl;
    }
    else {
        cout <<"Tree Not is Identical" << endl;
    }
    
    return 0;
}

/*
Sample Input1:
10
5
2
-1
-1
7
-1
-1
15
12
-1
-1
20
-1
-1
*/

/*
Sample Input2:
23
-1
34
56
22
-1
-1
34
-1
67
32
11
-1
-1
-1
11
29
-1
-1
-1
-1
*/