#include <iostream>
using namespace std;

void SpiralPrint(int arr[10][10], int row, int col) {
   int ans;
   
   int startingRow = 0;
   int startingCol = 0;
   int endingRow = row-1;
   int endingCol = col-1;
   
   int count = 0;
   int total = row * col;
   
   while(count < total) {
       
       for(int index = startingCol; index <= endingCol && count < total; index++) {
           ans = arr[startingRow][index];
           cout << ans <<" ";
           count++;
       }
       startingRow++;
       
       for(int index = startingRow; index <= endingRow && count < total; index++) {
           ans = arr[index][endingCol];
           cout << ans <<" ";
           count++;
       }
       endingCol--;
       
       for(int index = endingCol; index >= startingCol && count < total; index--) {
           ans = arr[endingRow][index];
           cout << ans <<" ";
           count++;
       }
       endingRow--;
       
       for(int index = endingRow; index >= startingRow && count < total; index--) {
           ans = arr[index][startingCol];
           cout << ans <<" ";
           count++;
       }
       startingCol++;
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

    SpiralPrint(arr, n, m); // Call function to calculate row-wise sum

    return 0;
}