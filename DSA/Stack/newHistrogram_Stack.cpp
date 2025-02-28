#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
private:
    vector<int> nextSamllerElement(vector<int> arr, int n) {
        stack<int> s;
        vector<int> ans;

        for(int i = n-1; i >= 0; i--) {

            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    vector<int> prevSamllerElement(vector<int> arr, int n) {
        stack<int> s;
        vector<int> ans;

        for(int i = 0; i < n; i++) {

            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

public:
    int largestRectangle(vector<int>& heights) {

        int n = heights.size();

        vector<int> next(n);
        next = nextSamllerElement(heights, n);

        vector<int> prev(n);
        next = prevSamllerElement(heights, n);

        int area = INT32_MIN;
        for(int i = 0; i < n; i++) {
            int l = heights[i];

            if(next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea); 
        }

        return area;
    }
};

int main() {

    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << sol.largestRectangle(heights) << endl;

    return 0;
}