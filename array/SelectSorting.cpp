#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    
    for (int i = 0 ; i < n; i++ ) {
        cout <<  arr[i] << " ";
    }
    cout << endl;
}

void selectSorting(int arr[], int size) {
    
    for(int i = 0; i < size-1; i++) {

        int midIndex = i;

        for(int j = i + 1; j < size; j++) {

            if(arr[midIndex] > arr[j]) {
                midIndex = j;
            }
        }
        swap(arr[midIndex], arr[i]);
    }
}

int main() {
    
    int arr[7] = {2, 12, 5, 44, 23, 7, 14};

    selectSorting(arr, 7);
    printArray(arr, 7);
}