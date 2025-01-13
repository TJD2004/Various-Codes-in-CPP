#include <iostream>
using namespace std;

int f(int x, int *py, int **ppz) {
    int y, z;
    **ppz += 1;
    z = **ppz;
    *py += 2;
    y = *py;
    x += 3;
    return x + y + z;
}

int main() {
    int c, *b, **a;
    c = 4;
    b = &c;
    a = &b;
    cout << f(c, b, a);
    return 0;
}

/*
    Solution description
    1. When f() is called, x=c=4, *py=*b=4, **ppz=4.
    2. **ppz += 1; modifies the value of c to 5.
    3. *py += 2; modifies the value of c to 7.
    4. x += 3; modifies the value of x to 7.
    5. The function returns x+y+z = 7+7+5 = 19.
*/