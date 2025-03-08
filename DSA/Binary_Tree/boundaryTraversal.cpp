#include<iostream>
#include<vector>
#include<queue>
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

void traverseLeft(Node* root, vector<int> &ans) {
    //base case
    if( (root == NULL) || (root->left == NULL && root->right == NULL) )
        return ;
        
    ans.push_back(root->data);
    if(root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);    
}

void traverseLeaf(Node* root, vector<int> &ans) {
    //base case
    if(root == NULL)
        return ;
        
    if(root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }
    
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node* root, vector<int> &ans) {
    //base case
    if( (root == NULL) || (root->left == NULL && root->right == NULL) )
        return ;
    
    if(root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);
        
    //wapas aagye
    ans.push_back(root->data);
        
}

vector <int> boundary(Node *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
        
    ans.push_back(root->data);
    
    //left part print/store
    traverseLeft(root->left, ans);
    
    //traverse Leaf Nodes
    
    //left subtree
    traverseLeaf(root->left, ans);
    //right subtree
    traverseLeaf(root->right, ans);
    
    //traverse right part
    traverseRight(root->right, ans);
    
    return ans;
}

int main() {

    Node* root = NULL;
    int cnt;

    // Build the tree (User Input Required)
    root = buildTree();
    cout<<endl;

    vector<int> ans;
    ans = boundary(root) ;

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    cout << endl;

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