#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i= 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void sorting(int arr[] , int size) {

    for(int i = 0; i<size-1 ; i++) {

        int minIndex = i;

        for(int j = i+1; j < size; j++) {

            if(arr[j] < arr[minIndex])
                minIndex = j;

        }
        swap(arr[minIndex], arr[i]);
    }
    
}

int main() {

    int arr[8] = {4, 6, 3, 5, 8};

    sorting(arr, 5 );
    printArray(arr, 5);

    return 0;
}