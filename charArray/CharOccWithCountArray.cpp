#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*  Program for Store count of character with there count in same cha array  */

int compress(vector<char> chars) {
    int i = 0;
    int ansIndex = 0;
    int n = chars.size();

    while(i < n) 
    {
        int j = i+1;
        
        while(j<n && chars[i] == chars[j]) 
        {
            j++;
        }

        chars[ansIndex++] = chars[i];

        int count = j-i;
        if( count > 1) {
            string cnt = to_string(count);
            for(char ch: cnt) 
            {
                chars[ansIndex++] = ch;
            }
        }
        i=j;
    }
     
   // cout << ansIndex;
    return ansIndex;
}

int main ()
{
    char ch;
    vector<char> ans;
    ans.push_back('a');
    ans.push_back('a');
    ans.push_back('a');
    ans.push_back('b');
    ans.push_back('b');
    ans.push_back('c');
    ans.push_back('c');
    ans.push_back('c');
    ans.push_back('c');
    int an=compress(ans);
    cout<<an;

}
