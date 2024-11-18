#include <iostream>
using namespace std;

int main() {

    int amt;
    
    cout << "Enter the Amount = ";
    cin >> amt;

    int hundered = amt / 100;
    int fifty = (amt - (hundered * 100)) / 50;
    int twenty = (amt - (hundered * 100) - (fifty*50)) / 20; 
    int one = (amt - (amt / 10) );

    int num;
    cout << "Enter note you want to count "<< endl;
    cout <<"1 - 100rs."<< endl << "2 - 50rs."<< endl << "3 - 20rs."<< endl<<"4 - 1rs."<<endl<< "your answer = ";
    cin >> num;

    switch(num) {

        case 1 : cout << "Notes = "<< hundered << endl;
                    break;

        case 2 : cout << "Notes = "<< fifty << endl;
                    break;
        case 3 : cout << "Notes = " << twenty << endl;          
                    break;

        case 4 : cout << "Notes = "<< one <<endl;
                    break;

    }
    cout << endl;

    return 0;
}

