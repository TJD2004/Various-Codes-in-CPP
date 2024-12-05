#include<iostream>
using namespace std;

void reverseChar(char name[] ,int n){
    int s = 0;
    int e = n-1;
    while(s<e){
        swap(name[s++], name[e--]);
    }
}

int getLength(char name[]) {
    int count = 0;
    for(int i = 0; name[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int main() {

    char name[20];

    cin >> name;
    int len = getLength(name);
    cout<<"length of characters :- "<<len<<endl;
    reverseChar(name,len);
    cout<<"Reverse of Name :- "<<name<<endl;

    return 0;
}