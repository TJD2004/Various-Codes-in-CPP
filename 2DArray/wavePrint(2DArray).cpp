#include <iostream>
using namespace std;

void wavePrint(int arr[10][10], int nRows, int nCols) {
    
    for(int col = 0; col < nCols; col++) {
        if(col&1){
            for(int row = nRows-1; row >= 0; row--){
                cout << arr[row][col] <<" ";
            }
        } else {
            for(int row = 0; row < nRows ; row++){
                cout << arr[row][col] << " ";
            }
        }
    }
}

int main() {
    int arr[10][10]; // Increased array size to handle larger inputs
    int n, m;

    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    cout << "Enter elements of the array:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j]; // Input array elements
        }
    }

    wavePrint(arr, n, m); // Call function to calculate row-wise sum

    return 0;
}