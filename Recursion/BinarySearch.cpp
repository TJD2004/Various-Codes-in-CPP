#include<iostream>
using namespace std;

bool BinarySearch(int *arr, int s, int e, int key) {

    if(s > e) {
        return false;
    }

    int mid = s + (e-s)/2;
    
    if(arr[mid] == key) {
        return true;
    }

    if(arr[mid] < key) {
        return BinarySearch(arr, mid+1, e, key);
    }
    else{
        return BinarySearch(arr, s, mid-1, key);
    }
}


int main() {

    int arr[100];
    int size;
    int key;

    cout << "Enter the size of array : ";
    cin  >> size;

    cout << "Enter the element to find in array : ";
    cin  >> key;

    cout << "Enter the number in array : ";

    for(int i=0; i < size ; i++) {
        cin >> arr[i];
    }

    int start = 0;
    int end = size-1;

    bool ans = BinarySearch(arr, start, end, key);

    if(ans) {
        cout << "Element exist in array";
    }
    else {
        cout << "Element not exist in array";
    }

    return 0;
}