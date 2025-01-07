#include <iostream>
using namespace std;


/*
   Code To Print Element Of Array (Int & Char) using For loop And Function
*/
void printArray( int arr[], int size){
   
    for(int i = 0; i<size; i++ ){

        cout << arr[i] << " ";
    }
    cout << endl;
    
}
 
void charArray(char ch[], int size){

    
    for(int i = 0; i<size; i++){
        cout << ch[i] <<" ";
    }
    cout << endl;


}
int main() {

    int third[5] = {2, 3, 4};
    printArray(third, 5);

    char ch[7] = {'a','b','k','f','j','*','%'};
    charArray(ch, 7);

    return 0;
}

/*
     Output :
             2 3 4 0 0 
             a b k f j * % 
*/