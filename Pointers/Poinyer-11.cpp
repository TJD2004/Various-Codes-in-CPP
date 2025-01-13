#include <iostream>
using namespace std;

void increment(int **p){
  (**p)++;
}

int main(){
 int num = 10;
 int *ptr = &num;
 increment(&ptr);
 cout << num << endl;
}

/*
    Solution description
    1. 'num' is initialized with the value 10.
    2. 'ptr' is a pointer that stores the address of 'num'.
    3. 'increment' function takes a double pointer as an argument, so '&ptr' is passed.
    4. Inside the 'increment' function, '**p' refers to the value of 'num', which is incremented by 1.
    5. After the function call, the value of 'num' becomes 11.
    So, the output for this is "11".

*/