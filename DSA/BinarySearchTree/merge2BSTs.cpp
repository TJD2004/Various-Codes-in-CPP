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

void inOrder(Node* root, vector<int> &in) { 
    if(root == NULL) {
        return;
    }

    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b) {
    vector<int> ans(a.size() + b.size());

    int i = 0, j = 0;

    while(i < a.size() && j < b.size()) {
        if(a[i] < b[j]) {
            ans.push_back(a[i]);
            i++;
        } else {
            ans.push_back(b[j]);
            j++;
        }
    }

    while(i < a.size()) {
        ans.push_back(a[i]);
        i++;
    }

    while(j < b.size()) {
        ans.push_back(b[j]);
        j++;
    }   

    return ans;
}

Node* inOrderToBST(vector<int> &arr, int start, int end) {
    if(start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);

    root->left = inOrderToBST(arr, start, mid - 1);
    root->right = inOrderToBST(arr, mid + 1, end);

    return root;
}

Node* mergeBST(Node* root1, Node* root2) {

    vector<int> bst1, bst2;
    inOrder(root1, bst1);
    inOrder(root2, bst2);

    vector<int> mergeArray = mergeArrays(bst1, bst2);

}

int inOderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    inOderTraversal(root->left);
    cout << root->data << " ";
    inOderTraversal(root->right);
}

int main() {

    Node* root1 = new Node(10);
    root1->left = new Node(5);
    root1->right = new Node(15);
    root1->left->left = new Node(2);
    root1->left->right = new Node(7);

    Node* root2 = new Node(12);
    root2->left = new Node(9);
    root2->right = new Node(20);
    root2->left->left = new Node(8);
    root2->left->right = new Node(11);

    Node* root = mergeBST(root1, root2);

    cout << "Array after merging: ";
    inOderTraversal(root);
    cout << endl;

    return 0;
}