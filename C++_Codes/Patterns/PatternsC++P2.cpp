#include<iostream>
using namespace std;

// int main() {

//     int n, row = 1, col;
//     cout << "Enter the number of rows: ";
//     cin >> n;

//     while(row <= n) {
//         col = 1;
//         while(col <= row) {
//             cout << "* ";
//             col++;
//         }
//         row++;
//         cout << endl;
//     }
//     return 0;
// }

/*
Output:
    Enter the number of rows: 5
    * 
    * * 
    * * * 
    * * * * 
    * * * * * 
    
*/


// int main() {

//     int n, row = 1, col;
//     cout << "Enter the number of rows: ";
//     cin >> n;
//     while(row <= n) {
//         col = 1;
//         while(col <= n-row+1) {
//             cout << "* ";
//             col++;
//         }
//         row++;
//         cout << endl;
//     }
//     return 0;
// }

/*
Output:
    Enter the number of rows: 5
    * * * * * 
    * * * * 
    * * * 
    * * 
    * 
    
*/

// int main() {
//     int n, row = 1, col;
//     cout << "Enter the number of rows: ";
//     cin >> n;
//     while(row <= n) {
//         int space = n - row;
//         while(space) {
//             cout << "  ";
//             space--;
//         } 

//         col = 1;
//         while(col <= row * 2 - 1) {
//             cout << "* ";
//             col++;
//         }
//         row++;
//         cout << endl;
//     }
//     return 0;
// }

/*
Output:
    Enter the number of rows: 5
            * 
          * * *
        * * * * *
      * * * * * * *
    * * * * * * * * *
    
*/

// int main() {

//     int n, row = 1, col;
//     cout << "Enter the number of rows: ";
//     cin >> n;
//     while(row <= n) {
//         int space = n - row + 1;
//         while(space) {
//             cout << "  ";
//             space--;
//         } 

//         col = 1;
//         while(col <= row) {
//             cout << "* ";
//             col++;
//         }
//         row++;
//         cout << endl;
//     }
//     return 0;
// }

/*
Output:
    Enter the number of rows: 5
    * * * * * 
      * * * * 
        * * * 
          * * 
            *
    
*/

// int main() {
//     int n, row = 1, col;
//     cout << "Enter the number of rows: ";
//     cin >> n;
//     while(row <= n) {
//         int space = n - row + 1;
//         while(space) {
//             cout << " ";
//             space--;
//         }
//         col = 1;
//         while(col <= row ) {
//             cout << "* ";
//             col++;
//         }
//         row++;
//         cout << endl;   
//     }
//     return 0;
// }

/*
Output:
    Enter the number of rows: 5
        * 
       * *
      * * *
     * * * *
    * * * * * 
    
*/


// int main() {
//     int n, row = 1, col;
//     cout << "Enter the number of rows: ";
//     cin >> n;
//     while(row <= n) {
//         int space = row - 1;
//         while(space) {
//             cout << "  ";
//             space--;
//         }
//         col = 1;
//         while(col <= n*2 - row*2 + 1) {
//             cout << "* ";
//             col++;
//         }
//         row++;
//         cout << endl;   
//     }
//     return 0;
// }

/*
Output:
    Enter the number of rows: 5
    * * * * * * * * * 
      * * * * * * *
        * * * * *
          * * *
            *
    
*/

// int main() {
//     int n, row = 1, col;
//     cout << "Enter the number of rows: ";
//     cin >> n;
//     while(row <= n) {
//         int space = row - 1;
//         while(space) {
//             cout << " ";
//             space--;
//         }
//         col = 1;
//         while(col <= n - row + 1) {
//             cout << "* ";
//             col++;
//         }
//         row++;
//         cout << endl;
//     }
//     return 0;
// }

/*
Output:
    Enter the number of rows: 5
    * * * * * 
     * * * *
      * * *
       * *
        *
    
*/


// int main() {
//     int n, row = 1, col;
//     cout << "Enter the number of rows: ";
//     cin >> n;
//     while(row <= n) {
//         int space = n - row;
//         while(space) {
//             cout << "  ";
//             space--;
//         }
//         col = 1;
//         while(col <= row*2-1) {
//             cout << "* ";
//             col++;
//         }
//         row++;
//         cout << endl;
//     }

//     row = 1;
//     while(row <= n) {
//         int space = row;
//         while(space) {
//             cout << "  ";
//             space--;
//         }
//         col = 1;
//         while(col <= n*2 - row*2-1) {
//             cout << "* ";
//             col++;
//         }
//         row++;
//         cout << endl;
//     }
//     return 0;
// }

/*
Output:
    Enter the number of rows: 5
            * 
          * * * 
        * * * * * 
      * * * * * * * 
    * * * * * * * * *
      * * * * * * *
        * * * * *
          * * * 
            *
    
*/

// int main() {
//     int n, row = 1, col;
//     cout << "Enter the number of rows: ";
//     cin >> n;

//     while(row <= n) {
//         int space = n - row;
//         while(space) {
//             cout << " ";
//             space--;
//         }
//         col = 1;
//         while(col <= row) {
//             cout << "* ";
//             col++;
//         }
//         row++;
//         cout << endl;
//     }

//     row = 1;
//     while(row <= n) {
//         int space = row;
//         while(space) {
//             cout << " ";
//             space--;
//         }
//         col = 1;
//         while(col <= n - row) {
//             cout << "* ";
//             col++;
//         }
//         row++;
//         cout << endl;
//     }
//     return 0;
// }

/*
Output:
    Enter the number of rows: 5
        * 
       * *
      * * *
     * * * *
    * * * * *
     * * * *
      * * *
       * *
        *
*/

// int main() {
//     int n, row = 1, col;
//     cout << "Enter the number of rows : ";
//     cin >> n;

//     while(row <= n) {
//         if(row == 1 || row == n) {
//             col = 1;
//             while(col <= n) {
//                 cout << "* ";
//                 col++;
//             }
//         }
//         else {
//             col = 1;
//             while(col <= n) {
//                 if(col == 1 || col == n) {
//                     cout << "* ";
//                 }
//                 else {
//                     cout << "  ";
//                 }
//                 col++;
//             }
//         }
//         row++;
//         cout << endl;
//     }
//     return 0;
// }

/*  
    Output :
        Enter the number of rows : 5
            * * * * * 
            *       *
            *       *
            *       *
            * * * * *
*/


// int main() {
//     int n, row = 1, col;
//     cout << "Enter the number of rows : ";
//     cin >> n;

//     while(row <= n) {
//         int space = n - row;
//         while(space) {
//             cout <<"  ";
//             space--;
//         }

//         if(row == 1 || row == n) {
//             col = 1;
//             while(col <= row) {
//                 cout << "* ";
//                 col++;
//             }
//         }
//         else {
//             col = 1;
//             while(col <= row) {
//                 if(col == 1 || col == row) {
//                     cout << "* "; 
//                 }
//                 else {
//                     cout << "  ";
//                 }
//                 col++;
//             }
//         }
//         row++;
//         cout << endl;
//     }
//     return 0;
// }

/*
    Output :
        Enter the number of rows : 5
                * 
              * *
            *   *
          *     * 
        * * * * *
*/

// int main() {
//     int n, row = 1, col;
//     cout << "Enter the number of rows : ";
//     cin >> n;

//     while(row <= n) {
//         int space = n - row;
//         while(space) {
//             cout <<" ";
//             space--;
//         }

//         if(row == 1 || row == n) {
//             col = 1;
//             while(col <= row) {
//                 cout << "* ";
//                 col++;
//             }
//         }
//         else {
//             col = 1;
//             while(col <= row) {
//                 if(col == 1 || col == row) {
//                     cout << "* "; 
//                 }
//                 else {
//                     cout << "  ";
//                 }
//                 col++;
//             }
//         }
//         row++;
//         cout << endl;
//     }
//     return 0;
// }

/*
    Output :
        Enter the number of rows : 5
              * 
             * *
            *   *
           *     *
          * * * * *
*/

int main() {
    int n, row = 1, col;
    cout << "Enter number of rows : ";
    cin >> n;

    while(row <= n) {
        int space = n - row;
        while(space) {
            cout <<" ";
            space--;
        }

        col = 1;
        while(col <= row) {
            if(col == 1 || col == row) {
                cout << "* "; 
            }
            else {
                cout << "  ";
            }
            col++;
        }
        row++;
        cout << endl;
    }

    row = 1;
    while(row <= n) {
        int space = row;
        while(space) {
            cout << " ";
            space--;
        }

        col = 1;
        while(col <= n -row) {
            if(col == 1 || col == n - row) {
                cout << "* ";
            }
            else {
                cout << "  ";
            }
            col++;
        }
        row++;
        cout << endl;
    }
    return 0;
}

/*
    Output :
        Enter number of rows : 5
            * 
           * *
          *   *
         *     *
        *       *
         *     *
          *   * 
           * *
            *
*/