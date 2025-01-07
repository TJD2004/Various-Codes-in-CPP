#include <iostream>
using namespace std;

/*
   Code To Alternate Swap Elements of Array
*/

void alterswap(int arr[], int n){

    for(int i = 0; i < n; i += 2){
        if(i+1 < n) {
             swap(arr[i], arr[i+1]);
        }     
    }
}
void printArray(int arr[], int n){

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;
}


int main() {

    int arr[6] = {1, 4, 2, 6, 10, 22};
    int brr[7] = {2, 4, 5, 6, 8, 6, 9};
    
    alterswap(arr, 6);
    alterswap(brr, 7);

    printArray(arr, 6);
    printArray(brr, 7);

    return 0;

}

/*
   Output : 
           4 1 6 2 22 10 
           4 2 6 5 6 8 9 
*/