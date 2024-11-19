#include <iostream>
using namespace std;

/*
   Code to Count No. of 1 in Input BY converting It in Binary
*/


int main() {
    
    int n;
    cout << "Enter Number : ";
    cin >> n;

    int count = 0;
    while(n!=0) {
        if(n & 1) {
            count++;
        }
        n = n >> 1;
    }

    cout << "No. Of 1 : " << count;
    return 0;
 }

 /*
    Output : 
            Enter Number : 33
            No. Of 1 : 2

 */