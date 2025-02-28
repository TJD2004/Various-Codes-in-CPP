#include<iostream>
#include<stack>
using namespace std;

/*  Last in First Out (LIFO)  */

int main() {
    stack<string>s;

    s.push("Tushar");
    s.push("Janardan");
    s.push("Dharmik");

    cout<<"Top Element is : "<<s.top()<<endl;
    cout<<"Size : "<<s.size()<<endl;
    cout<<"Empty or not"<<s.empty()<<endl;
}