#include <iostream>
using namespace std;

/*
    Code to Reverse Enter Number 
*/

int main() {
    int n;
    cout << "Enter Number : ";
    cin >> n;

    int number = 0;
        while (n != 0) {
            int remainder = n % 10;
            n = n / 10;
            number = number * 10 + remainder;
           
        }
        cout << "Reverse of Enter Number is : "  << number;
        return 0;

}

/*
    Output :
            Enter Number : 345673
            Reverse of Enter Number is : 376543
*/