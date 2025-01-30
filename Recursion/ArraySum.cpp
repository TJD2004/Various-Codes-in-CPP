#include<iostream>
using namespace std;


int ArraySum(int arr[], int size) {

    if(size == 0) {
        return 0;
    }

    if(size == 1) {
        return arr[0];
    }
    
    int remainArray = ArraySum(arr+1, size-1);
    int sum = arr[0] + remainArray;
    return sum;
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

    int ans = ArraySum(arr, size);
    cout << "Sum of the Element in the array is : " << ans << endl;

    return 0;
}