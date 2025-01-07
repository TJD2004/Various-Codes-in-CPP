#include <iostream>
using namespace std;

/*
    Code to Sum all Element in Array
*/

int getSum(int arr[], int n){

    int sum = 0;
    
    for( int i = 0; i < n; i++){

        sum = sum + arr[i];
    }
    
    return sum;
}


int main() {

    int size;
    cout << "Enter the size of array = ";
    cin >> size;

    cout << "Enter Element to create Array : ";
    
    int num[100];
    for(int i = 0; i < size ; i++) {
        cin >> num[i];
    }
    cout << endl;
    cout << "Sum of all values in array is = "<< getSum(num, size) <<endl;

    return 0;
}

/*
    Output :
            Enter the size of array = 5
            Enter Element to create Array : 3 3 5 2 6
            Sum of all values in array is = 19
*/
    