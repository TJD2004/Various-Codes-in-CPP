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

    l.pop_front();
    l.pop_back();


}