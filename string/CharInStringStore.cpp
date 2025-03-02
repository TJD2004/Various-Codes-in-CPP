#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    int arr[26] = {0}; 

    // Loop through the string
    for(int i = 0; i < s.length(); i++) {
        char ch = s[i];
        int val = 0;

        if(ch >= 'a' && ch <= 'z') {
            val = ch - 'a';  // Calculate the index for lowercase letters
        }

        else if(ch >= 'A' && ch <= 'Z') {
            val = ch - 'A';  // Calculate the index for uppercase letters
        }

        // Increment the frequency count for the character if it's a letter
        if(val >= 0 && val < 26) {
            arr[val]++;
        }
    }

    cout << "Frequency of letters (case-insensitive):" << endl;
    for(int i = 0; i < 26; i++) {
        if(arr[i] > 0) {
            cout << char('a' + i) << ": " << arr[i] << endl;
        }
    }

    return 0;
}
