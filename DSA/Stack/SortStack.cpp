#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &stack, int num) {
    //base case
    if(stack.empty() || (!stack.empty() && stack.top() < num) ) {
        stack.push(num);
        return;
    }
    
    int n = stack.top();
    stack.pop();
    
    //recusrive call
    sortedInsert(stack, num);
    
    stack.push(n);
}

void sortStack(stack<int> &stack)
{
	//base case
    if(stack.empty()) {
        return ;
    }
    
    int num = stack.top();
    stack.pop();
    
    //recursive call
    sortStack(stack);
    
    sortedInsert(stack, num);
}

int main() {
    stack<int> stack;
    stack.push(30);
    stack.push(10);
    stack.push(20);
    stack.push(50);
    stack.push(40);

    sortStack(stack);

    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }

    return 0;
}
