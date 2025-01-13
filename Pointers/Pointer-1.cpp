#include <iostream>
using namespace std;
int main()
{
  int arr[] = {4, 5, 6, 7};
  int *p = (arr + 1);
  cout << *arr + 9;
  return 0;
}


/*
        The output is calculated as follows:

        *arr retrieves the first element of the array arr, which is 4.
        Adding 9 to 4: 4 + 9 = 13.
        Therefore, the output of the program is 13.
*/