#include<iostream>
using namespace std;

int Factorial(int n) {
    
    if(n == 0) 
        return 1;
    
    int Factorial_of_n_minus_1 = Factorial(n-1);
    int Factorial_of_n = n * Factorial_of_n_minus_1;
    
    return Factorial_of_n;
}

int main() {

    int n;
    cout << "Enter Number : ";
    cin >> n;

    cout <<"Factorial of " << n <<"numbers is " << Factorial(n);

    return 0;
}