#include <iostream>
using namespace std;

void printArray( int arr[], int size){
   
   cout <<"Printing the array "<<endl;
    for(int i = 0; i<size; i++ ){

        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Printing Done"<<endl;
}
 
void charArray(char ch[], int size){

    cout <<"Printing the array "<<endl;
    for(int i = 0; i<size; i++){
        cout << ch[i] <<" ";
    }
    cout << endl;
    cout << "Printing Done";

}
int main() {

    int third[5] = {2, 3, 4};
    printArray(third, 5);

    char ch[7] = {'a','b','k','f','j','*','%'};
    charArray(ch, 7);

    return 0;
}