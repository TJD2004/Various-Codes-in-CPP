#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;


int main() {
    unordered_map<string,int> m;
    m["Tushar"] = 1;
    m["Janardan"] = 2;
    m["Dharmik"] = 3;
    m["Bheem"] = 4;

    cout<<m["Tushar"]<<endl; // O(1) average case, O(n) worst case

    for(auto i:m) {
        cout<<i.first<<" "<<i.second<<endl; // i.frst = key, i.second = value
    }

    cout<<"finding Tushar :- "<<m.count("Tushar")<<endl; // present or not

    m.erase("Tushar"); // delete the key-value pair

    for(auto i:m) {
        cout<<i.first<<" "<<i.second<<endl;
    }

    auto it = m.find("Bheem"); // returns an iterator to the key-value pair
    // if not found, returns m.end()

    for(auto i=it;i!=m.end();i++){
        cout<<(*i).first<<" "<<(*i).second<<endl; // i.first = key, i.second = value
    }
}