#include<iostream>
#include<vector>
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

Node* solve(vector<int> &preorder, int min ,int max, int &i) {

    if(i >= preorder.size()) {
        return NULL;
    }

    if(preorder[i] < min || preorder[i] > max) {
        return NULL;
    }

    Node* root = new Node(preorder[i++]);
    root->left = solve(preorder, min, root->data, i);
    root->right = solve(preorder, root->data, max, i);
    return root;
}

Node* preorderToBST(vector<int> &preorder) {

    int min = INT32_MIN;
    int max = INT32_MAX;
    int i = 0;
    return solve(preorder, min, max, i);
}

int main() {

    vector<int> preorder = {10, 2, 1, 13, 11};
    Node* root = preorderToBST(preorder);

    return 0;
}
