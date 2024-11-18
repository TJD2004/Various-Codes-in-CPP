#include <iostream>
#include <math.h>
using namespace std;


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
    cin >> x >> y;
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