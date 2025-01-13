// C++ Program to implement Jagged array 
// 2nd way: Dynamic 2D array 
#include <iostream> 
using namespace std; 

int main() 
{ 
	// system("cls"); 

	int row, col; 
	row = 3; 

	// Create Row Array- dynamic array of pointers 
	int** arr = new int*[row]; 
	int *sizes= new int[row]; 

	// no of columns for each row as input from user 
	for (int i = 0; i < row; i++) { 
		
		cin>>col;	  
		sizes[i]=col; 
		// store each col number in size ( if row and col 
		// are taken as input) 
	

		*(arr + i) = new int[sizes[i]]; 
		// creating column of sizes[i] for each row 
	} 

	// input from user 
	for (int i = 0; i < row; i++) { 
		for (int j = 0; j < sizes[i]; j++) { 
			cin>>arr[i][j];
		} 
	} 

	cout << "elements in matrix form as follow" << endl; 
	for (int i = 0; i < row; i++) { 
		for (int j = 0; j < sizes[i]; j++) { 
			cout << arr[i][j] << " "; 
		} 
		cout << endl; 
	} 

	for(int i=0; i<row; i++) {
        delete [] arr[i];
    }   

    delete []arr;


	return 0; 
}
