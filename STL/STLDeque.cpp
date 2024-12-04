#include<iostream>
#include<deque>
using namespace std;

int main() {
    
    deque<int> d;

    d.push_back(2);
    d.push_front(4);

    for(int i:d){
        cout<<i<<" ";
    } 

    cout<<"Size : "<<d.size()<<endl;
    cout<<"Element at 2nd Index : "<<d.at(2)<<endl;
    cout<<"First : "<<d.front()<<endl;
    cout<<"Last : "<<d.back()<<endl;

    d.pop_front();
    d.pop_back();

    d.erase(d.begin(),d.begin()+1);
    
}