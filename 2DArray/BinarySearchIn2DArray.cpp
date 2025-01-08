#include <iostream>
using namespace std;

void BinarySearchIn2DArray(int arr[10][10], int row, int col, int target) {
    int start = 0;
    int end = row * col - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        int r = mid / col; // Row index
        int c = mid % col; // Column index
        int element = arr[r][c];
        
        if (element == target) {
            cout << "Target Found at index (" << r << "," << c << ")\n";
            return; // Exit the function once the target is found
        } else if (element < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
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