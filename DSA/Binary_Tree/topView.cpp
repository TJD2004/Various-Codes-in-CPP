#include<iostream>
#include<vector>
#include<map>
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

vector<int> topView(Node *root)
{
    vector<int> ans;
    if(root == NULL) 
    {
        return ans;
    }
    
    map<int,int> topNode;
    queue<pair<Node*, int> > q;
    
    q.push(make_pair(root, 0));
    
    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;
        
        //if one value is present for a HD, then do nothing
        if(topNode.find(hd) == topNode.end())
            topNode[hd] = frontNode -> data;
            
        if(frontNode->left)
            q.push(make_pair(frontNode->left, hd-1));
        if(frontNode->right)
            q.push(make_pair(frontNode->right, hd+1));
    }
    
    for(auto i:topNode) 
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main() {

    Node* root = NULL;
    int cnt;

    // Build the tree (User Input Required)
    root = buildTree();
    cout<<endl;

    vector<int> ans;
    ans = topView(root) ;

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