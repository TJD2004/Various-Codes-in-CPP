#include <iostream>
using namespace std;

/*
	Code to find Unique Element in Array 
*/



int main() {

    int arr[100] = { 2, 3, 2, 4, 3};
    int n = 5;
    int ans = 0;

    for(int i = 0; i<n+1; i++) {
        
        ans = ans^arr[i];
        
    }
    cout << "Unique Element in Given Array is : " << ans;

    return 0;

}

/*
	Output : 
            Unique Element in Given Array is : 4
*/

