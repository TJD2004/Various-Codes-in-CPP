#include<iostream>
using namespace std;


bool LinearSearch(int arr[], int size , int key) {

    if(size == 0) {
        return false;
    }

    if(arr[0] == key) {
        return true;
    }

    else {
        int remainArray = LinearSearch(arr+1, size-1, key);
        return remainArray;
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

    bool ans = LinearSearch(arr, size, key);

    if(ans) {
        cout << "Element exist in array";
    }
    else {
        cout << "Element not exist in array";
    }

    return 0;
}