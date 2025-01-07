#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    
    for (int i = 0 ; i < n; i++ ) {
        cout <<  arr[i] << " ";
    }
    cout << endl;
}

void bubbleSorting(int arr[], int size) {
    
    for(int i = 1; i < size-1; i++) {
        bool swapped = false;
        for(int j = 0; j < size-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped==false) {
            break;
        }
    }
}

int main() {
    
    int arr[7] = {2, 12, 5, 44, 23, 7, 14};

    bubbleSorting(arr, 7);
    printArray(arr, 7);
}