#include <iostream>
using namespace std;

int PIoM(int arr[], int n) {

    int s = 0;
    int e = n - 1;

    int mid = s + (e - s) / 2;

    while (s < e) {
        if (arr[mid] < arr[mid + 1]) {
                s = mid + 1;
        } 
        else 
        {
            e = mid;
        }
        mid = s + (e - s) / 2;

    }
    
    return s;
}

int main() {

    int arr[5] = {1, 2, 5, 8, 1};
    
    cout << "Peak Index in Mountain array is  " << PIoM(arr, 5);
}