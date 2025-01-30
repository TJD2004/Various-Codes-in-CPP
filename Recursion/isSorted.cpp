#include<iostream>
using namespace std;

bool isSorted(int arr[], int size) {

    if(size == 0 || size == 1) {
        return true;
    }

    if(arr[0] > arr[1]) {
        return false;
    }

    else {
        bool remainPart = isSorted(arr+1, size-1);
        return remainPart;
    }
}

int main() {

    int arr[100];
    int size;

    cout << "Enter the size of array : ";
    cin  >> size;

    cout << "Enter the number in array : ";
    for(int i=0; i < size ; i++) {
        cin >> arr[i];
    }

    bool ans = isSorted(arr, size);

    if(ans) {
        cout << "Array is Sorted";
    }
    else {
        cout << "Array is Not Sorted";
    }

    return 0;
}