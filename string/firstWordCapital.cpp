#include<iostream>
using namespace std;

// Function to convert the first character of a string to uppercase
string UpperCase(string s) {
    if (!s.empty() && s[0] >= 'a' && s[0] <= 'z') {
        s[0] = s[0] - 'a' + 'A';
    }
    return s;
}

int main()
{
    string s, temp, res;
    getline(cin, s); // To read the entire line, including spaces
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            if (!temp.empty()) {
                res += UpperCase(temp) + " ";
                temp.clear(); // Reset temp for the next word
            }
        } else {
            temp += s[i];
        }
    }
    
    // Process the last word
    if (!temp.empty()) {
        res += UpperCase(temp);
    }

    cout << res << endl;

    return 0;
}