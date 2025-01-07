#include<iostream>
using namespace std;


/*  Permutation in string */

bool checkEqual( int a[26], int b[26]) 
{
    for(int i = 0; i<26; i++) {
        if(a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

bool PermutationInString( string s1, string s2)
{

    int count1[26] = {0};
    
    for(int i = 0; i<s1.length(); i++) {
        int index = s1[i] - 'a';
        count1[index]++;
    }

    int i =0;
    int windowSize = s1.length();
    int count2[26] = {0};

    while(i < windowSize && i < s2.length() ) {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    if( checkEqual(count1, count2)) 
        return 1;

    while(i < s2.length() ) {
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;

        char oldChar = s2[i-windowSize];
        index = oldChar - 'a';
        count2[index]--;
        i++;

        if( checkEqual(count1, count2)) 
            return 1;
    }

    return 0;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    if(PermutationInString(s1, s2)) {
        cout << "Premutation is exist";
    } else {
        cout << "Premutation is not exist";
    }
}