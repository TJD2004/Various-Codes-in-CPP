#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    
    for (int i = 0 ; i < n; i++ ) {
        cout <<  arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int n) {
    int i = 1;
    while(i<n){
        int temp = arr[i];
        int j = i-1;
        while(j>=0){
            if(arr[j]>temp){
                arr[j+1] = arr[j];
                j--;
            }
            else{
                break;
            }
        }
        i++;
        arr[j+1] = temp;
    }
}

int main() {
    
    int arr[9] = {5,3,6,35,34,44,2,1,7};

    insertionSort(arr,9);
    printArray(arr, 9);
}