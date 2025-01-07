#include<iostream>
#include<vector>
using namespace std;

void rotate(int arr[] , int n, int k) {
    
    k = k%n;
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    for (int i = 0; i < n-k; i++) {
        arr[i] = arr[i+k];
    }
    for (int i = 0; i < n; i++) {
        arr[n-k+i] = temp[i];
    }
}

void print(int arr[], int n){

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;
}

int main() {
    
    int k = 2;
    int arr[5] ={2,5,3,6,7};

    rotate(arr,5,k);
    print(arr,5);

    
}