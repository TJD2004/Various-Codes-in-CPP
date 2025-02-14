#include <iostream>
#include <climits>
using namespace std;

/*
   Code to Find Maximum And Minimum Value In Array
*/

int getMax( int num[], int n){
    
    int max = INT_MIN;

    for(int i = 0; i<n; i++){
        if(num[i] > max){
            max = num[i];
        }
    }
    
    return max;

}

int getMin( int num[], int n){
    
    int min = INT_MAX;

    for(int i = 0; i<n; i++){
        if(num[i] < min){ 
            min = num[i];
        }
        
    }

    return min;

}



int main() {

    int size;
    cout << "Enter Size : ";
    cin >> size;

    int num[100];

    cout << "Enter Elements To Creat Array : ";

    for( int i = 0; i<size; i++ ){

        
        cin >> num[i] ;
    }

    cout << "Maximum value is = " << getMax(num, size)<<endl;
    cout << "Minimum value is = " << getMin(num, size)<<endl;

    return 0;
}

/*
   output : 
            Enter Size : 5
            Enter Elements To Creat Array : 3 4 5 6 2 
            Maximum value is = 6
            Minimum value is = 2
            
*/