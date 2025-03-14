#include <iostream>
using namespace std;

/*
    Code to find Index of 1st and Last ELement in Array using Binary Search
*/

int firstOcc(int arr[] ,int n, int key) {

    int s = 0 , e = n - 1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key) {
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid]) {
            s = mid + 1;
        }
        else if(key < arr[mid]) {
            e = mid - 1;
        }

        mid = s + (e-s)/2;
        

    }
    return ans;
}


int lastOcc(int arr[] ,int n, int key) {

    int s = 0 , e = n - 1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key) {
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr[mid]) {
            s = mid + 1;
        }
        else if(key < arr[mid]) {
            e = mid - 1;
        }

        mid = s + (e-s)/2;
        

    }
    return ans;
}



int main() {

    int even[12] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5};

    cout << "First Occurance of 3 is at Index " << firstOcc(even, 12, 3) << endl;
    cout << "Last Occurance of 3 is at Index " << lastOcc(even, 12, 3) << endl;

    return 0;
}

/*
   Output : 
            First Occurance of 3 is at Index 2
            Last Occurance of 3 is at Index 10

*/