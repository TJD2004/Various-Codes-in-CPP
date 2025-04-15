#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;

int maxfrequency(vector<int> &arr, int n) {

    unordered_map<int,int> count;

    int maxFreq = 0;
    int maxAns = 0;
    for(int i=0;i<arr.size();i++) {
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for(int i=0;i<arr.size();i++) {
        if(count[arr[i]] == maxFreq) {
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5, 1, 2, 1};
    int n = arr.size();
    cout<<maxfrequency(arr,n)<<endl;
    return 0;
}

/* 
    Output:
    1
*/