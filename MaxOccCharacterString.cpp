#include<iostream>
using namespace std;

char getMaxOccCharaterString(string s) {
    int arr[26] = {0};

    for(int i = 0; i < s.length(); i++ ){
        char ch = s[i];
        int val = 0;
        
        if(ch >= 'a' && ch <= 'z') {
            val = ch - 'a';
        }
        else 
        {
            val = ch - 'A';
        }
        arr[val]++;
    }

    int maxi = -1 , ans = 0;
    for(int i =0; i<26; i++) {
        if(maxi < arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }
    char finalAns = 'a' + ans;
    return finalAns;
}

int main() {

    string s;
    cin >> s;
    cout << getMaxOccCharaterString(s) << endl;

    return 0;
}