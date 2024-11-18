#include <iostream>
using namespace std;

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
    
    int num[100];
    for(int i = 0; i < size ; i++) {
        cin >> num[i];
    }
    cout << endl;
    cout << "Sum of all values in array is = "<< getSum(num, size) <<endl;

    return 0;
}
    