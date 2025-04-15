#include<iostream>
#include<queue>
#include<vector> 
using namespace std;

class Node {

    public:
        int data;
        int row;
        int col;

    Node(int data1, int row, int col) {
        this -> data = data;
        this -> row = row;
        this -> col = col;
    }

};

class compare {
    public:
        bool operator()(Node* a, Node* b) {
            return a -> data > b -> data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int> > &kArrays, int k) {

    priority_queue<vector<int>, vector<Node*>, compare> minHeap;

    for(int i=0; i<k; i++) {
        Node* tmp = new Node(kArrays[i][0], i, 0);
        minHeap.push(tmp);
    }

    vector<int> ans;

    while(minHeap.size() > 0) {
        Node* tmp = minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();

        int row = tmp -> row;
        int col = tmp -> col;

        if(col + 1 < kArrays[row].size()) {
            Node* next = new Node(kArrays[row][col+1], row, col+1);
            minHeap.push(next);
        }
    }
    return ans;
}

int main() {
    vector<vector<int> > kArrays = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    int k = 3;

    vector<int> result = mergeKSortedArrays(kArrays, k);

    for(int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}