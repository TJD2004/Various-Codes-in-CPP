#include<iostream>
#include<list>
using namespace std;

int main() {
    
    list<int> l;

    l.push_back(2);
    l.push_front(4);

    for(int i:l){
        cout<<i<<" ";
    } 
    cout<<"Size : "<<l.size()<<endl;
    cout<<"First : "<<l.front()<<endl;
    cout<<"Last : "<<l.back()<<endl;

    l.pop_front();
    l.pop_back();


}