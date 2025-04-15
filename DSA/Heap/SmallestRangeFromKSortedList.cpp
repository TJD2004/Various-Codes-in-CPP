#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    int row; 
    int col; 

    Node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class Compare {
public:
    bool operator()(Node* &a, Node* &b) {
        return a->data > b->data; // Min heap based on data
    }
};
int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini = INT32_MAX, maxi = INT32_MIN;
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for(int i=0; i<k; i++) {
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element, i, 0));
    }
    
    int start = mini, end = maxi;

    while(!minHeap.empty()) {

        Node* temp = minHeap.top();
        minHeap.pop();
        mini = temp->data;
        
        if(maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }

        if(temp->col+1 < n) {
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minHeap.push(new Node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else {
            break;
        }
    }
    return (end - start + 1);
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<vector<int>> a(k, vector<int>(n));
    for(int i=0; i<k; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    cout << kSorted(a, k, n) << endl;
    return 0;
}