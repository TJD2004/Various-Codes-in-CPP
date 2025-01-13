#include<iostream>
using namespace std;

void changeSign(int *p){
  *p = (*p)  *  -1;
}

int main(){
  int a = 10;
  changeSign(&a);
  cout << a << endl;
}

/*
    Solution description
    1. The changeSign function is called with the address of 'a' as an argument.
    2. Inside the changeSign function, the value at the address pointed by 'p' is multiplied by -1.
    3. This changes the value of 'a' to -10.
    4. The main function then prints the value of 'a', which is now -10.

*/