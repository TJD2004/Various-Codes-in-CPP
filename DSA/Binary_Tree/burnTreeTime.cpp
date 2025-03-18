#include<iostream>
#include<map>
#include<queue>
using namespace std;   

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to create parent mapping and return the target node
Node* createParentMapping(Node* root, map<Node*, Node*>& nodeToParent, int target) {
    Node* res = NULL;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        if(front->data == target) {
            res = front; // Found target node
        }

        if(front->left) {
            nodeToParent[front->left] = front;  // Map left child to its parent
            q.push(front->left);
        }
        if(front->right) {
            nodeToParent[front->right] = front;  // Map right child to its parent
            q.push(front->right);
        }
    }
    return res;
}

// Function to calculate the minimum time to burn the tree starting from the target node
int burnTree(Node* root, map<Node*, Node*>& nodeToParent) {
    map<Node*, bool> visited;
    queue<Node*> q;

    q.push(root);
    visited[root] = true; // Mark the root as visited

    int ans = 0;

    // Process nodes level by level (BFS approach)
    while(!q.empty()) {
        int size = q.size();
        bool flag = 0; // flag to check if we have to increment time

        for(int i = 0; i < size; i++) {
            Node* front = q.front();
            q.pop();

            // Check left child
            if(front->left && !visited[front->left]) {
                flag = 1;
                q.push(front->left);
                visited[front->left] = true;
            }

            // Check right child
            if(front->right && !visited[front->right]) {
                flag = 1;
                q.push(front->right);
                visited[front->right] = true;
            }

            // Check parent node
            if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }

        // If any node was added in this level, it means time has passed
        if(flag == 1) {
            ans++;
        }
    }

    return ans;
}

// Function to find the minimum time to burn the tree
int minTime(Node* root, int target) {
    int ans = 0;
    map<Node*, Node*> nodeToParent;

    // Step 1: Create the parent mapping and find the target node
    Node* targetNode = createParentMapping(root, nodeToParent, target);

    // Step 2: Calculate the minimum time to burn the tree
    ans = burnTree(targetNode, nodeToParent);

    return ans;
}

int main() {
    // Sample Tree: 
    //           1
    //         /   \
    //        2     3
    //       / \   / \
    //      4   5 6   7
    // Target = 3

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int target = 3;

    // Function to find minimum time to burn the tree from the target node
    int timeToBurn = minTime(root, target);

    cout << "Minimum time to burn the tree: " << timeToBurn << " units." << endl;

    return 0;
}
