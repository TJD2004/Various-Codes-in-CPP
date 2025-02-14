#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i= 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr[100], size, insert, count = 1;
    cin >> size >> insert;
    for(int i = 0; i < size ; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i < size; i++) {
        if(arr[i-1] > insert) {
            cout << "-1";
        }
        if(arr[i-1] < insert && arr[i+1] > insert) {
            arr[i] = insert;
            break;
        }
    }

    printArray(arr,size);

    for(int i=0; i < size; i++) {
        if(arr[i] < arr[i+1]) {
            count++;
        }
    }
    cout << count;
}