#include<iostream>
#include<array>
using namespace std;

int main() {
    int basic[3] = {1, 2, 3};
    
    array<int, 4> a = {1, 2, 3, 4};

    cout<<"Element at 2nd index is : "<<a.at(2)<<endl;
    cout<<"Empty or not"<<a.empty()<<endl;
    cout<<"first Element : "<<a.front()<<endl;
    cout<<"Last Element : "<<a.back()<<endl; 
}