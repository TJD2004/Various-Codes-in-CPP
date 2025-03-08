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

vector<int> zigZagTraversal(Node* root)
{
    vector<int> result;
    if(root == NULL)
    	return result;
    	
    queue<Node*> q;
    q.push(root);
    	
    bool leftToRight = true;
    	
    while(!q.empty()) {
    	    
    	int size = q.size();
    	vector<int> ans(size);
    	    
    	//Level Process
    	for(int i=0; i<size; i++) {
    	        
    	    Node* frontNode = q.front();
    	    q.pop();
    	        
    	    //normal insert or reverse insert 
    	    int index = leftToRight ? i : size - i - 1;
    	    ans[index] = frontNode -> data;
    	        
    	    if(frontNode->left)
    	        q.push(frontNode -> left);
    	            
    	    if(frontNode->right)
    	        q.push(frontNode -> right);
    	    }
    	    
    	    //direction change karni h
    	    leftToRight = !leftToRight;
    	   
    	    for(auto i: ans) {
    	        result.push_back(i);
    	}  
    }
    return result;
}

int main() {

    Node* root = NULL;
    int cnt;

    // Build the tree (User Input Required)
    root = buildTree();
    cout<<endl;

    vector<int> ans;
    ans = zigZagTraversal(root) ;

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