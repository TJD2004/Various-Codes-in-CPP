#include <iostream>
using namespace std;

/*
    Code For Binary Search 
*/

// Time Complexity of Binary Search is = O(log N)

int binarySearch(int arr[] , int size, int key) {

    int start = 0;
    int end = size - 1;

    int mid = (start + end) / 2;

    while(start <= end) {

        if(arr[mid] == key) {
            return mid;
        }

        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }

        mid = (start + end) / 2;
    }
    return -1;
}

int main() {

    int even[6] = {2, 4, 6, 8, 12, 18};
    int odd[5] = {3, 5, 7, 9, 11};

    int evenIndex = binarySearch(even , 6, 28);

    cout << "Index of 18 is " << evenIndex << endl;

    int oddIndex = binarySearch(odd , 5, 11);

    cout << "Index of 11 is " << oddIndex << endl;



    return 0;
}

/*
    Output : 
            Index of 18 is -1
            Index of 11 is 4
*/