#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque<long long int> dq;
    vector<long long> ans;

    // Initial window of size K
    for(int i = 0; i < K; i++) {
        if(A[i] < 0) {
            dq.push_back(i);
        }
    }

    // Add the first negative element of the first window to the answer
    if(dq.size() > 0) {
        ans.push_back(A[dq.front()]);
    } else {
        ans.push_back(0);
    }

    // Process the rest of the windows
    for(int i = K; i < N; i++) {
        // Remove elements that are out of the current window
        if(!dq.empty() && i - dq.front() >= K) {
            dq.pop_front();
        }

        // Add the current element if it's negative
        if(A[i] < 0) {
            dq.push_back(i);
        }

        // Add the first negative element of the current window to the answer
        if(dq.size() > 0) {
            ans.push_back(A[dq.front()]);
        } else {
            ans.push_back(0);
        }
    }

    return ans;
}

int main() {
    long long int N, K;
    cout << "Enter the size of the array: ";
    cin >> N;
    cout << "Enter the window size K: ";
    cin >> K;

    long long int A[N];
    cout << "Enter the elements of the array: ";
    for(long long int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<long long> result = printFirstNegativeInteger(A, N, K);

    cout << "First negative integers in every window of size " << K << ": ";
    for(long long int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
