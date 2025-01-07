#include <iostream>
using namespace std;

/*
    Code to find Fibonacci Series
*/

int main() {
    int n;
    cout << "Enter Number : ";
    cin>>n;
    
    int a = 0;
    int b = 1;

    cout<<a<<" "<<b<<" ";

    for(int i = 1; i<+n; i++){
        int nextnumber = a + b;
        cout<<nextnumber<<" ";

        a = b;
        b = nextnumber;
    }
    return 0;
    
} 

/*
    Output :
            Enter Number : 10
            0 1 1 2 3 5 8 13 21 34 55
*/
