#include<iostream>
#include<queue>
#include<vector>
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

void solve(Node* root, int k, int &count, vector<int> path) {

    if(root == NULL) {
        return ;
    }

    path.push_back(root->data);

    solve(root->left, k, count, path);
    solve(root->right, k, count, path);

    int size = path.size();
    int sum = 0;
    for(int i = size-1; i>=0; i--)  {
        sum += path[i];
        if(sum == k) 
            count++;
        
    }

    path.pop_back();

}

int KSum(Node* root, int k) {

    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
}

int main() {

    Node* root = buildTree();
    int k = 5;
    
    int result = KSum(root, k);

    cout << "Number of paths having sum 5 : " << result << endl;

    return 0;
}

