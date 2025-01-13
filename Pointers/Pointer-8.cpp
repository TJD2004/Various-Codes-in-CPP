#include <iostream>
using namespace std;
void Q(int z)
{
  z += z;
  cout<<z << " ";
}

void P(int *y) 
{
  int x = *y + 2;
  Q(x);
  *y = x - 1; 
  cout<<x << " ";
}

int main()
{
  int x = 5;
  P(&x);
  cout<<x;
  return 0;
}

/*
    Solution description
    1. In the main function, x is initialized with the value 5.
    2. The function P is called with the address of x (&x).
    3. Inside P, *y will give the value as 5 and thus local variable x of function P is updated with 7.
    4. The function Q is called with the value 7, which doubles it and prints 14.
    5. Back in P, x is updated to 7 - 1 = 6, and 7 is printed.
    6. Finally, in the main function, the updated value of x (6) is printed
*/