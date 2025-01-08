#include <iostream>
using namespace std;

/*  Program Of Binary Search when both row and column are sorted in 2D Array */

void BinarySearchIn2DArray(int arr[10][10], int row, int col, int target) {
    int rowIndex = 0;
    int colIndex = col-1;
    
    while(rowIndex < row && colIndex >=0) {
        
        int element = arr[rowIndex][colIndex];
        
        if(element == target) {
            cout << "Target Found at index (" << rowIndex <<","<<colIndex <<")\n";
            return ;
        }
        else if(element < target) {
            rowIndex++;
        }
        else {
            colIndex--;
        }
    }
    
    // If the loop ends, the target is not found
    cout << "Target not found\n";
}

int main() {
    int arr[10][10]; // Fixed-size array
    int n, m, target;

    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    cout << "Enter target: ";
    cin >> target;

    cout << "Enter elements of the array:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    BinarySearchIn2DArray(arr, n, m, target); // Perform binary search

    return 0;
}