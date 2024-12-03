#include<iostream>
#include<queue>
using namespace std;

int main() {
    int n;
    priority_queue<int>maxi;   
    priority_queue<int, vector<int>,greater<int>>mini;

    maxi.push(1);
    maxi.push(3);
    maxi.push(13);
    maxi.push(10);

    for(int i=0; i<n; i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }

    mini.push(1);
    mini.push(3);
    mini.push(13);
    mini.push(10);

    for(int i=0; i<n; i++){
        cout<<maxi.top()<<" ";
        mini.pop();
    }

}   