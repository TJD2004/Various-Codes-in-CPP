#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int kthSmallest(int arr[], int n, int k) {
    priority_queue<int> maxHeap;

    for(int i = 0; i < n; i++) {
        maxHeap.push(arr[i]);
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    return maxHeap.top();
}


int kthLargest(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i < n; i++) {
        minHeap.push(arr[i]);
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }

    return minHeap.top();
}


int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << kthSmallest(arr, n, k) << endl;
    cout << kthLargest(arr, n, k) << endl;

    return 0;
}