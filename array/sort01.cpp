#include <iostream>
#include <algorithm>
using namespace std;

/*
    Code To Sort O & 1
*/


void printArray(int arr[], int n) {
    for(int i= 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort01(int arr[], int n) {

    int left = 0, right = n -1;

    while(left < right) {

        while(arr[left] == 0  && left < right) {
            left++;
        }

        while(arr[right] == 1 && left < right) {
            right--;
        }

        if(left < right) {

            swap(arr[left], arr[right]);
            left++;
            right--;
        }

    }
}

int main() {

    int arr[8] = {1, 0, 1, 0, 0, 1, 0, 0};

    sort01(arr, 8);
    printArray(arr, 8);

    return 0;
}

/*
    Output :
            0 0 0 0 0 1 1 1 

*/