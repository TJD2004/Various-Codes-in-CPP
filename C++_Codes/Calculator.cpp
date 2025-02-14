#include<iostream>
using namespace std;

/*
   Simple Calulator With 2 input using Switch Case
*/

int main() {

    int a, b;

    cout <<"Enter the value of a " << endl;
    cin >> a;

    cout <<"Enter the value of b " << endl;
    cin >> b;

    char op;
    cout <<"Enter the operation you want to perform " << endl;
    cin >> op;

    switch( op ) {

        case '*': cout << (a*b) <<endl;
                  break;

        case '-': cout << (a-b) <<endl;
                  break;

        case '+': cout << (a+b) <<endl;
                  break;

        case '/': cout << (a/b) <<endl;
                  break;

        case '%': cout << (a%b) <<endl;
                  break;   

        default: cout <<"Please enter the valid operation" <<endl;       
    }
    cout << endl;

    return 0;


}

/*
    output : 
            Enter the value of a 
            24
            Enter the value of b 
            55
            Enter the operation you want to perform 
            *
            1320
*/