#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
    public:
        string FirstNonRepeating(string A) {
            unordered_map<char, int> count;  
            queue<int> q;                    
            string ans = "";                 

            for(int i = 0; i < A.length(); i++) {
                char ch = A[i];             
                count[ch]++;             
                q.push(ch);                

                // This inner loop checks the front of the queue to find the first non-repeating character
                while(!q.empty()) {
                    if(count[q.front()] > 1) {   // If the character at the front repeats
                        q.pop();               
                    }
                    else {
                        ans.push_back(q.front());  
                        break;                      
                    }
                }

                // If the queue is empty, no non-repeating character is found, so append '#'
                if(q.empty()) {
                    ans.push_back('#');
                }
            }
            return ans;  
        }
};

int main() {
    Solution sol;

    string A;
    cout << "Enter the string: ";  
    cin >> A;

    string result = sol.FirstNonRepeating(A);

    cout << "First non-repeating characters in the stream: " << result << endl;

    return 0;
}
