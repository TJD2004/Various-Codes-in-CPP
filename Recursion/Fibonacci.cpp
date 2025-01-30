#include<iostream>
using namespace std;

int Fib(int n) {
    
    if(n == 0 || n == 1) 
        return (n);

    int Fib_of_n = Fib(n-1) + Fib(n-2);

    return Fib_of_n;
    
}

int main() {

    int n, i=0;
    cout << "Enter Number : ";
    cin >> n;

    cout << "\nFibonacci Series Of "<< n << " number is : ";

    while(n > i) {
        cout << " " << Fib(i);
        i++; 
    }

    return 0;
}