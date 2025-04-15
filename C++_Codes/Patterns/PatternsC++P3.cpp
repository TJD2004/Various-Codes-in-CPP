#include<iostream>
using namespace std;

// int main() {
//     int n, row = 1, col;
//     cout << "Enter the number of rows: ";
//     cin >> n;
    
//     while(row <= n) {
//         col = 1;
//         while(col <= row) {
//             cout << col <<" ";
//             col++;
//         }
//         row++;
//         cout << endl;
//     }
//     return 0;
// }

/* Output :
    Enter the number of rows: 5
    1 
    1 2 
    1 2 3 
    1 2 3 4 
    1 2 3 4 5
*/

// int main() {
//     int n, row = 1, col;
//     cout << "Enter the number of rows: ";
//     cin >> n;
    
//     while(row <= n) {
//         col = 1;
//         while(col <= row) {
//             cout << row <<" ";
//             col++;
//         }
//         row++;
//         cout << endl;
//     }
//     return 0;
// }

/* Output :
    Enter the number of rows: 5
    1 
    2 2 
    3 3 3 
    4 4 4 4 
    5 5 5 5 5
*/

// int main() {
//     int n, row = 1, col;
//     cout << "Enter the number of rows: ";
//     cin >> n;
    
//     while(row <= n) {
//         int space = n-row;
//         while(space) {
//             cout << "  ";
//             space--;
//         }
//         col = 1;
//         while(col <= row) {
//             cout << col <<" ";
//             col++;
//         }
//         row++;
//         cout << endl;
//     }
//     return 0;
// }

/* Output :
    Enter the number of rows: 5
          1 
        1 2 
      1 2 3 
    1 2 3 4
*/

// int main() {
//     int n, row = 1, col;
//     cout << "Enter the number of rows: ";
//     cin >> n;
        
//     while(row <= n) {
//         int space = n-row;
//         while(space) {
//                 cout << "  ";
//                 space--;
//             }
//         col = 1;
//         while(col <= row) {
//             cout << row <<" ";
//             col++;
//         }
//         row++;
//         cout << endl;
//     }
//     return 0;
// }

/* Output :
    Enter the number of rows: 5
          1 
        2 2 
      3 3 3 
    4 4 4 4
*/

// int main() {
//     int n, row = 1, col, num = 1;
//     cout << "Enter the number of rows: ";
//     cin >> n;
        
//     while(row <= n) {
//         col = 1;
//         while(col <= row) {
//             cout << num++ <<" ";
//             col++;
//         }
//         row++;
//         cout << endl;
//     }
//     return 0;
// }

/* Output :
    Enter the number of rows: 5
    1 
    2 3 
    4 5 6 
    7 8 9 10 
    11 12 13 14 15
*/

// int main() {
//     int n, row = 1, col, num = 1;
//     cout << "Enter the number of rows: ";
//     cin >> n;
        
//     while(row <= n) {
//         int space = n-row;
//         while(space) {
//                 cout << "  ";
//                 space--;
//             }
//         col = 1;
//         while(col <= row) {
//             cout << num++ <<" ";
//             col++;
//         }
//         row++;
//         cout << endl;
//     }
//     return 0;
// }

/*
    Output :
    Enter the number of rows: 4
          1 
        2 3 
      4 5 6 
    7 8 9 10 
*/

// int main() {
//     int n, row = 1, col;
//     cout << "Enter the number of rows: ";
//     cin >> n;

//     while(row <= n) {
//         int space = n-row;
//         while(space) {
//             cout << "  ";
//             space--;
//         }
//         col = 1;
//         while(col <= row){
//             cout << col <<" ";
//             col++;
//         }

//         col = 1;
//         while(col <= row-1) {
//             cout << row - col <<" ";
//             col++;
//         }
//         row++;
//         cout << endl;
//     }
//     return 0;
// }

/* Output :
    Enter the number of rows: 5
          1 
        1 2 1 
      1 2 3 2 1 
    1 2 3 4 3 2 1 
  1 2 3 4 5 4 3 2 1 
*/

// int main() {
//     int n, row = 1, col;
//     cout << "Enter the number of rows: ";
//     cin >> n;

//     while(row <= n) {
//         int space = n-row;
//         while(space) {
//             cout << "  ";
//             space--;
//         }
//         col = 1;
//         while(col <= row*2-1) {
//             cout << col <<" ";
//             col++;
//         }
//         row++;
//         cout << endl;
//     }
//     return 0;
// }

/* Output :
    Enter the number of rows: 5
          1 
        1 2 3 
      1 2 3 4 5 
    1 2 3 4 5 6 7 
  1 2 3 4 5 6 7 8 9 
*/

