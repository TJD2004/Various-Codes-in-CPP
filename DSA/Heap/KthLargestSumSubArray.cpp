#include<iostream>
#include<algorithm>
#include<queue>
#include<vector> 
using namespace std;

// Approach 1: Brute Force
int kthLargestSum1(vector<int> &arr, int k) {

    vector<int> ans;
    int n = arr.size();
     
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            ans.push_back(sum);
        }
    }
    sort(ans.begin(), ans.end());

    return ans[ans.size() - k];
}

// Approach 2: Using MIN HEAP
int kthLargestSum2(vector<int> &arr, int k) {

    priority_queue<int, vector<int>, greater<int> > mini;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(mini.size() < k){
                mini.push(sum);
            } 
            else {
                if(mini.top() < sum) {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 3;

    int ans1 = kthLargestSum1(arr, k);
    cout<<"Kth Largest sum (Brute force) : "<< ans1 << endl;
    
    int ans2 = kthLargestSum2(arr, k);
    cout<<"Kth Largest sum (Using MIN HEAP) : "<< ans2 << endl;

    return 0;
}