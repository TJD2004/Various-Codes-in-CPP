#include <bits/stdc++.h>
using namespace std;

/*  Code For Rvevrse String */

string reverseString(string s) {
    int end = s.length()-1;
    int str = 0;
    for(int i = 0; i<end; i++){
        swap(s[str], s[end]);
        str++;
        end--;
    }
    return s;
}

int main() {
	string s;
    cin >> s;
	string temp = reverseString(s);
	cout<<temp;

}