#include <iostream>
#include <string>
using namespace std;

void reverse(string &s) {
    int st = 0;
    int e = s.length() - 1;
    while (st < e) {
        swap(s[st], s[e]);
        st++;
        e--;
    }
}

int main() {
    string s, temp;
    getline(cin, s); // Read input with spaces

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            reverse(temp);
            cout << temp << " ";
            temp.clear();
        } else {
            temp += s[i];
        }
    }

    // Handle the last word
    if (!temp.empty()) {
        reverse(temp);
        cout << temp;
    }

    return 0;
}