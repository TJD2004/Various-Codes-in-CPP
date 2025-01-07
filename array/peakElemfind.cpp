#include<iostream>
using namespace std;

/*
   Code to Find Index of Peak Element In Array
*/

int main() {

    // int i = 0;
    // int j = 1;
    int arr[5] = {18, 2, 45, 55, 6};

    // while(i <= 5 && j <=5) {
        
    //     if(arr[i] < arr[j]) {
    //         i++;
    //     }
    //     else{
    //         j++;
    //     }
    // } 

    // if(arr[i]>arr[j]) {
    //      cout << i << endl;

    // }
    // else{
    //      cout << j << endl;

    // }
    
    //  OR

    int mx = arr[0];
    int ans = 0;

    for(int i = 1; i <= 5; i++) {
        if(arr[i] > mx) {
            arr[i] = mx;
            ans = i;
        }
    }
    cout << "Index of Peak Element in Array : " << ans ;

    return 0;
}

/*
   Output : 
            Index of Peak Element in Array : 3

*/