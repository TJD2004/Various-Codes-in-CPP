#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int>v;
    cout<<"Size : "<<v.capacity()<<endl;

    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);

    cout<<"Size : "<<v.size()<<endl;
    cout<<"Element at 2nd Index : "<<v.at(2)<<endl;
    cout<<"First : "<<v.front()<<endl;
    cout<<"Last : "<<v.back()<<endl;

    v.pop_back();
    for(int i:v){
        cout<<i<<" ";
    } 

    v.clear();
    cout<<"size : "<<v.size()<<endl;
}