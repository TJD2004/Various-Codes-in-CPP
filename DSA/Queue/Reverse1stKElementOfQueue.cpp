#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {

    stack<int> s;

    // Reverse the first k elements
    for(int i = 0; i < k; i++) {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // Push the reversed elements back into the queue
    while(!s.empty()) {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    // Move the remaining elements to the back of the queue
    int t = q.size() - k;

    while(t--) {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}

int main() {
    int n, k;
    cout << "Enter the size of the queue: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    queue<int> q;

    cout << "Enter the elements of the queue: ";
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        q.push(val);
    }

    q = modifyQueue(q, k);

    // Display the modified queue
    cout << "Modified queue: ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
