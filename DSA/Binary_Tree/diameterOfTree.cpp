#include<iostream>
using namespace std;

/* Diameter in Binary Tree : Largest path between two end Node  */

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

pair<int,int> diameterfast(Node* root) {

    if(root == NULL) {
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameterfast(root->left);
    pair<int,int> right = diameterfast(root->right);

    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(opt1, max(opt2, opt3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(Node* root) {

    return diameterfast(root).first;
}

int main() {

    Node* root = NULL;

    // Build the tree (User Input Required)
    root = buildTree();

    cout <<"Diameter in Tree : " << diameter(root);
    cout << endl;

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