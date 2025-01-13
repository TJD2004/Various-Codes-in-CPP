#include <iostream>
using namespace std;
int main()
{
  char arr[20];
  int i;
  for(i = 0; i < 10; i++) {
    *(arr + i) = 65 + i;
  }
  *(arr + i) = '\0';
  cout << arr;
  return 0;
}

/* 
        The output is generated as follows:

        A loop assigns ASCII values starting from 65 (character A) to arr, filling it with characters A to J (for i from 0 to 9).
        A null terminator ('\0') is added at arr[10] to mark the end of the string.
        The cout << arr; statement prints the characters up to the null terminator.
        Thus, the output is ABCDEFGHIJ.


*/