#include<iostream>
#include<string.h>
using namespace std;

bool isPalindrom(string& str, int start, int end) {

    if(start > end) {
        return 0;
    }

    if(str[start] != str[end]) {
        return 0;
    }
    else {
        return isPalindrom(str, start++, end--);
    }
    
}

int main() {

    string str;
    cout << "Enter Any String To Reverse : ";
    cin >> str;

    int start = 0, end = str.length()-1;

    return 0;

}
