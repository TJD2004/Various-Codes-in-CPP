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


pair<bool,int> isSumTreeFast(Node* root) {
        
    //base case
    if(root == NULL) {
        pair<bool,int> p = make_pair(true, 0);
        return p;
    }
        
    if(root->left == NULL && root->right == NULL ) {
        pair<bool,int> p = make_pair(true, root->data);
        return p;
    }
        
    pair<bool,int> leftAns = isSumTreeFast(root->left);
    pair<bool,int> rightAns = isSumTreeFast(root->right);
        
    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;
        
    int leftSum = leftAns.second;
    int rightSum = rightAns.second;
        
    bool condn = root->data == leftSum + rightSum;
        
    pair<bool, int> ans;
        
    if(isLeftSumTree && isRightSumTree && condn) {
        ans.first = true;
        ans.second = root->data + leftSum + rightSum ;
    }
    else
    {
        ans.first = false;
    }  
    return ans;
        
}

bool isSumTree(Node* root) {

    return isSumTreeFast(root).first;

}

int main() {

    Node* root = NULL;

    // Build the tree (User Input Required)
    root = buildTree();

    if(isSumTree(root)) {
        cout <<"Tree is Sum Tree" << endl;
    }
    else {
        cout <<"Tree NOT is Sum Tree" << endl;
    }

    return 0;
}

/*
Sample Input:
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
