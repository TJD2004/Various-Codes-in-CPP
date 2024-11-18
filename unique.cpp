#include <iostream>
using namespace std;


int main() {

    int arr[100] = { 2, 3, 2, 4, 3};
    int n = 5;
    int ans = 0;

    for(int i = 0; i<n+1; i++) {
        
        ans = ans^arr[i];
        
    }
    cout << ans;

    return 0;

}
