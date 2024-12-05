#include <iostream>  
#include <cctype> // For isalnum and tolower  
#include <string>  

using namespace std;  

 
bool valid(char ch) {  
    return isalnum(ch); 
}  


char toLowerCase(char ch) {  
    return tolower(ch); 
}  


string validCharacter(const string& s) {  
    string v;
    for (char ch : s) {  
        if (valid(ch)) {  
            v += ch; 
        }  
    }  
    return v;
}  

 
bool isPalindrome(const string& s) {  
    string filtered = validCharacter(s); 
    string lowerCaseStr; 

    for (char ch : filtered) {  
        lowerCaseStr += toLowerCase(ch);  
    }  

    string reversedStr = string(lowerCaseStr.rbegin(), lowerCaseStr.rend());  
    return lowerCaseStr == reversedStr;
}  

int main() {  
    string s;  
    cout << "String: ";  
    getline(cin, s); 

    cout << "Is Palindrome: " << (isPalindrome(s) ? "Yes" : "No") << endl;  

    return 0;  
}