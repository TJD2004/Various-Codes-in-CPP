#include<iostream>
#include<vector>
using namespace std;


void merge(int a1[], int n, int a2[], int m, int a3[]){

    int i =0, j =0, k =0;

    while(i<n && j<m) {
        if(a1[i]<a2[j]) {
            a3[k++] = a1[i++];
        }
        else 
        {
            a3[k++] = a2[j++];
        }
    }

    while(i<n) {
        a3[k++] = a1[i++];
    }

    while(j<m) {
        a3[k++] = a1[j++];
    }
}

void print(int arr[], int n){

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;
}

int main() {

    int arr1[5] = {1,3,5,7,9};
    int arr2[3] = {2,4,6};

    int arr3[8] = {0};

    merge(arr1, 5, arr2, 3, arr3);

    print(arr3, 8);

    return 0;
}
