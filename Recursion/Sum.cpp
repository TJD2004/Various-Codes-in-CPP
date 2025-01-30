#include<iostream>
using namespace std;

int Sum(int n) {
    
    if(n == 0) 
        return 1;
    
    int Sum_of_n_minus_1 = Sum(n-1);
    int Sum_of_n = n + Sum_of_n_minus_1;
    
    return Sum_of_n;
}

int main() {

    int n;
    cout << "Enter Number : ";
    cin >> n;

    cout <<"Sum of " << n <<"numbers is " << Sum(n);

    return 0;
}