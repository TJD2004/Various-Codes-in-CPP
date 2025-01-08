#include <iostream>
using namespace std;

void sumRows(int arr[10][10], int n, int m) {
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < m; j++) {
            rowSum += arr[i][j]; // Add each element in the row
        }
        cout << "Sum of row " << i + 1 << ": " << rowSum << endl; // Print row sum
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

    sumRows(arr, n, m); // Call function to calculate row-wise sum

    return 0;
}