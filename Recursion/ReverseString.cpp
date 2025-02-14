#include<iostream>
#include<string.h>
using namespace std;

void Reverse(string& str, int start, int end) {

    if(start > end) {
        return ;
    }
    swap(str[start++], str[end--]);
    Reverse(str, start, end);
}

int main() {

    string str;
    cout << "Enter Any String To Reverse : ";
    cin >> str;

    int start = 0, end = str.length()-1;

    Reverse(str, start, end);
    cout << "Reverse of Entered String is : " << str << endl;

    return 0;

}
