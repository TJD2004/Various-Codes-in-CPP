#include<iostream>
#include<stack>
using namespace std;

int main() {

    string str1 = "Tushar";
    stack<char> ans; 
    string reversedStr = "";

    // Push all characters of the string onto the stack
    for(int i = 0; i < str1.size(); i++) {
        ans.push(str1[i]);
    }

    // Pop characters from the stack to reverse the string
    while(!ans.empty()) {
        reversedStr += ans.top();
        ans.pop();
    }

    cout << "Reversed String: " << reversedStr << endl;

    return 0;
}
