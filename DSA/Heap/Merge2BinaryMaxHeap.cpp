#include<iostream>
#include<queue>
#include<vector>
using namespace std;    

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

vector<int> MergeHeap(vector<int> &a, vector<int> &b, int n, int m) {
    
    vector<int> res;
    for(auto i:a) {
        res.push_back(i);
    }
    for(auto i:b) {
        res.push_back(i);
    }

    int size = res.size();
    for(int i = size/2 - 1; i >= 0; i--) {
        heapify(res, size, i);
    }

}

int main() {
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    vector<int> res = MergeHeap(a, b, a.size(), b.size());

    for(auto i:res) {
        cout << i << " ";
    }

    return 0;
}