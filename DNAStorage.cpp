#include <iostream>  
#include <string>  
using namespace std;  

int main() {  
    string s;  
    cout << "Enter DNA number: ";  
    cin >> s;  
    string temp;  
    
    // Loop through the string two characters at a time  
    for (int i = 0; i < s.length(); i += 2) {  
        // Ensure we don't go out of bounds  
        if (i + 1 >= s.length()) {  
            cout << "Incomplete pair at the end of input, skipping." << endl;  
            break;  
        }  

        // Translate binary pairs to DNA characters  
        if (s[i] == '0' && s[i + 1] == '0') {  
            temp += 'A';  // Append 'A'  
        } else if (s[i] == '0' && s[i + 1] == '1') {  
            temp += 'T';  // Append 'T'  
        } else if (s[i] == '1' && s[i + 1] == '0') {  
            temp += 'G';  // Append 'G'  
        } else if (s[i] == '1' && s[i + 1] == '1') {  
            temp += 'C';  // Append 'C'  
        }  
    }  

    cout << "Translated DNA: " << temp << endl;  

    return 0;  
}