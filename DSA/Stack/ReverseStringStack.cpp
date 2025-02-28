#include<iostream>
#include<stack>
using namespace std;

int main() {

    string str1 = "Tushar";
    stack<char> ans; 
    string reversedStr = "";

    for(int i = 0; i < str1.size(); i++) {
        ans.push(str1[i]);
    }

    while(!ans.empty()) {
        reversedStr += ans.top();
        ans.pop();
    }

    cout << "Reversed String: " << reversedStr << endl;

    return 0;
}
