#include <iostream>
using namespace std;

/*
   Code for Linear Search
*/

bool search(int arr[], int size, int key){

    for(int i = 0; i<size; i++){

        if(arr[i] == key){
            return 1;
        }
        
    }
    return 0;
}

int main() {
    
    int arr[10] = {2, -4, 7, 22, -5};
    
    int key;
    cout << "Enter the value of Key = ";
    cin >> key;

    bool found = search(arr, 10, key);

    if(found){
        cout << "Key is present"<<endl; 
    }
    else{
        cout << "Key is not present"<<endl;
    }

    return 0;
}

/*
    Output :
            Enter the value of Key = 5
            Key is not present
            
*/