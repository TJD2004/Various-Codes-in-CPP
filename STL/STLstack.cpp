#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<string>s;

    s.push("Tushar");
    s.push("Janardan");
    s.push("Dharmik");

    cout<<"Top Element is : "<<s.top()<<endl;
}