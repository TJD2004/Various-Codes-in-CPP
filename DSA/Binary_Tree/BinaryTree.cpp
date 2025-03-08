#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree() {
    int data;
    cout << "Enter the data: ";
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    node* root = new node(data);

    cout << "Enter the data to insert in left of " << data << ": ";
    root->left = buildTree();
    cout << "Enter the data to insert in right of " << data << ": ";
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(node* root) {
    if (root == NULL) return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void inorder(node* root) {

    if(root == NULL) 
        return ;
        
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);   
}

void preorder(node* root) {

    if(root == NULL) 
        return ;
    
    cout << root->data << " ";    
    preorder(root->left);
    preorder(root->right);   
}

void postorder(node* root) {

    if(root == NULL) 
        return ;
        
    postorder(root->left);
    postorder(root->right);  
    cout << root->data << " "; 
}

int main() {
    node* root = NULL;
    
    // Build the tree (User Input Required)
    root = buildTree();

    // Print level order traversal
    cout << "Level order traversal of the tree:" << endl;
    levelOrderTraversal(root);

    inorder(root);
    cout << endl;

    preorder(root);
    cout << endl;
    
    postorder(root);
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

Explanation of Input:
- Root node = 10
- Left child of 10 = 5
- Left child of 5 = 2
- 2 has no children (-1, -1)
- Right child of 5 = 7 (7 has no children)
- Right child of 10 = 15
- Left child of 15 = 12 (12 has no children)
- Right child of 15 = 20 (20 has no children)

Tree Structure:
        10
       /  \
      5    15
     / \   /  \
    2   7 12  20

Sample Output:
Level order traversal of the tree:
10
5 15
2 7 12 20
*/