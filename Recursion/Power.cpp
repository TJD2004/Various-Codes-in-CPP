#include<iostream>
using namespace std;

int Power(int n, int m) {

    if(m == 0) {
        return 1;
    }

    int n_to_Power_m_minus1 = Power(n,m-1);
    int n_to_Power_m = n * n_to_Power_m_minus1;

    return  n_to_Power_m;
}

int main() {

    int n , m;
    cout << "Enter Base : ";
    cin >> n;
    cout <<"Enter Power : ";
    cin >> m;

    cout << n << " To The Power " << m << " is " << Power(n,m);

    return 0;
}