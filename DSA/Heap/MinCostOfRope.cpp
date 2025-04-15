#include<iostream>
#include<queue>
#include<vector>
using namespace std;

long long minCost(long long arr[], long long n) {
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    for(long long i = 0; i < n; i++) {
        minHeap.push(arr[i]);
    }
    
    long long cost = 0;
    while(minHeap.size() > 1) {
        long long first = minHeap.top();
        minHeap.pop();
        long long second = minHeap.top();
        minHeap.pop();
        
        long long sum = first + second;
        cost += sum;
        minHeap.push(sum);
    }  
    return cost;
}

int main() {
    long long arr[] = {4, 3, 2, 6};
    long long n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum cost to connect ropes: " << minCost(arr, n) << endl;
    return 0;
}
    