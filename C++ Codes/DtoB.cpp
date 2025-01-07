#include<iostream>
#include<math.h>
using namespace std;

/*
   Code To convert Decimal to binary
*/

int main() {
    int n;
    cout << "Enter Number : ";
    cin >> n;
    
    
    int ans = 0 || 1;
    int i = 0;
    while(n!=0) {

        int bit = n & 1;
        ans = bit * pow(10, i) + ans;

        n = n >> 1;
        i++;
    }

    cout << "Answer is "<< ans <<endl;
    return 0;
}

/*
   Output : 
            Enter Number : 34
            Answer is 100011
*/