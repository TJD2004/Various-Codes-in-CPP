#include <iostream>
#include <stack>
using namespace std;

void reverseString(stack<char>& s, char str[], int index) {
    // Base case
    if (str[index] == '\0') {
        return;
    }

    s.push(str[index]);

    // Recursive call
    reverseString(s, str, index + 1);
}

void printReversedString(stack<char>& s) {
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;

    stack<char> s;

    // Reverse the string using recursion
    reverseString(s, str, 0);

    cout << "Reversed string: ";
    printReversedString(s);

    return 0;
}
