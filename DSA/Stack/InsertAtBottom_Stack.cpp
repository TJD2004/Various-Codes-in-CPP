#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& s, int x) {
    //base case
    if(s.empty()) {
        s.push(x);
        return ;
    }
    
    int num = s.top();
    s.pop();
    
    //recursive call
    solve(s, x);
    
    s.push(num);
}


stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
    return myStack;
}

int main() {
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    int x = 4;
    myStack = pushAtBottom(myStack, x);

    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    return 0;
}
