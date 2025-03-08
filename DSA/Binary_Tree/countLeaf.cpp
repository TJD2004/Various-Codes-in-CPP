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
    

void inorder(Node *root, int &count) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left, count);
   	
    //leaf node
    if(root->left == NULL && root->right == NULL) {
        count++;
    }
    
    inorder(root->right, count);

}


int noOfLeafNodes(Node *root){
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}

int main() {

    Node* root = NULL;
    int cnt;

    // Build the tree (User Input Required)
    root = buildTree();
    inorder(root, cnt);

    cout <<"Total leaf in Tree : " << noOfLeafNodes(root);
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