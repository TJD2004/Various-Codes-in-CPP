#include <bits/stdc++.h>
using namespace std;

/*  Program to reverse Word If Space (" ") is occurred */

string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    string s = "Tushar Janardan Dharmik";
    string temp = "", result = "";

    // Loop from 0 to s.length() - 1 to avoid trailing space
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {  // End of word
            result += reverseString(temp) + " "; // Reverse the word and append
            temp = ""; // Clear temp for the next word
        } else {
            temp += s[i]; // Build the current word
        }
    }

    // Add the last word after the loop finishes
    result += reverseString(temp);

    cout << result << endl;
    return 0;
}