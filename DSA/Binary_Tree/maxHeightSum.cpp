#include <iostream>
#include <queue>
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

void solve(Node* root, int len, int &maxlen, int sum, int &maxSum) {

    if(root == NULL) {
        if(len > maxlen) {
            maxlen = len;
            maxSum = sum;
        }
        else if(len == maxlen) {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum = sum + root->data;

    solve(root->left, len+1, maxlen, sum, maxSum);
    solve(root->right, len+1, maxlen, sum, maxSum);
}

int sumOfLongRootToLeafPath(Node* root) {

    int len = 0;
    int maxlen = 0;

    int sum = 0;
    int maxSum = INT32_MIN;

    solve(root, len, maxlen, sum, maxSum);
}

int main() {
    Node* root = buildTree();
    
    int result = sumOfLongRootToLeafPath(root);

    cout << "Sum of the longest path is: " << result << endl;

    return 0;
}

/* Sample Input:
1
2
4
-1
-1
5
-1
-1
3
6
-1
-1
7
1
-1
*/
