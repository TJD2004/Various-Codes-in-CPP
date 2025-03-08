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

int height(Node* root) {

    if(root == NULL) {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

pair<bool,int> isBalancedfast(Node* root) {
    
    if(root == NULL) {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> left = isBalancedfast(root->left);
    pair<bool,int> right = isBalancedfast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = (left.second - right.second) <= 1;
    
    pair<bool,int> ans;
    ans.second = max(left.second, right.second);

    if(leftAns && rightAns && diff) {
        ans.first = true;
    } 
    else {
        ans.first = false;
    }

    return ans;
}

bool isBalanced(Node* root) {

    /* Brute force 
    if(root == NULL) {
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = (height(root->left) - height(root->right)) <= 1;

    if(left && right && diff) {
        return 1;
    } 
    else {
        return false;
    }
    */
   return isBalancedfast(root).first;
}

int main() {

    Node* root = NULL;

    // Build the tree (User Input Required)
    root = buildTree();
    cout << endl;

    if(isBalanced(root)) {
        cout <<"Tree is Balanced" << endl;
    }
    else {
        cout <<"Tree Not is Balanced" << endl;
    }

    return 0;
}

/*
Sample Input:
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