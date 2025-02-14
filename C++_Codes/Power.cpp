#include <iostream>
#include <math.h>
using namespace std;

/*
    Code To find x to the power y
*/


// int pow(int x, int y) {


//     int ans = 1;

//     for(int i = 1; i<=y; i++) {

//         ans = ans * x;
//     }
//     return ans;
// }
// int main() {
//     int a, b; 
//     cin >> a >> b;
    
//     int answer = pow(a, b);
    
//     cout << answer;

//     return 0;
// }

int pow() {

    int x, y;
    cout << "Value of X = ";
    cin >> x ;

    cout << "Value of Y = ";
    cin >> y ;

    int ans = 1;

    for(int i = 1; i<=y; i++) {

        ans = ans * x;
    }
    return ans;
}
int main() {
    
    int answer = pow();
    
    cout << "Answer is " << answer;

    return 0;
}

/*
    Output :
            Value of X = 3
            Value of Y = 5
            Answer is 243
*/