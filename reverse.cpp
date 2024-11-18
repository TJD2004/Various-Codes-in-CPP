#include <iostream>
using namespace std;

//reverse number
int main() {
    int n;
    cin >> n;

    int number = 0;
        while (n != 0) {
            int remainder = n % 10;
            n = n / 10;
            number = number * 10 + remainder;
           
        }
        cout << number;
        return 0;

}        