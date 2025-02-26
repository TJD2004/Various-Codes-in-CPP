#include <iostream>
#include <stack>
using namespace std;

void reverseString(stack<char>& s, char str[], int index, int length) {
    // Base case
    if (index == length) {
        return;
    }

    // Push the current character onto the stack
    s.push(str[index]);

    // Recursive call
    reverseString(s, str, index + 1, length);
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

    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    stack<char> s;

    // Reverse the string using recursion
    reverseString(s, str, 0, length);

    cout << "Reversed string: ";
    printReversedString(s);

    return 0;
}
