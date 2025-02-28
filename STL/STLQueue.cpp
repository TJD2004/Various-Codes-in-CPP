#include<iostream>
#include<queue>
using namespace std;

/*  First In First Out (FIFO)  */

int main() {
    queue<string>q;
    queue<string>mini;


    q.push("Tushar");
    q.push("Janardan");
    q.push("Dharmik");


    mini.push("2");
    mini.push("3");
    mini.push("4");
    mini.push("0");

    cout<<"Size : "<<q.size()<<endl;
    cout<<"First : "<<q.front()<<endl;
    cout<<"Last : "<<q.back()<<endl;

       
    

}