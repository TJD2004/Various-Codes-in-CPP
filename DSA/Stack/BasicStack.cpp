#include<iostream>
using namespace std;

class Stack {

    public:
    int *arr;
    int top;
    int size;

    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {

        if(size - top >= 0) {
            top++;
            arr[top] = element;
        }
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {

        if(top >= 0) {
            top--;
        }
        else {
            cout <<"Stack Underflow" << endl;
        }
    }

    int peek() {

        if(top >= 0)
            return arr[top];
        
        else {
            cout << "Stack is Empty" << endl;
        }
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        else{
            return false;
        }
    }
};

int main() {

    Stack st(5);

    st.push(24);
    st.push(33);
    st.push(45);
    st.push(64);
    st.push(46);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    if(st.isEmpty()) {
        cout << "Stack is Empty";
    }
    else {
        cout << "Stack is not Empty";
    }



    return 0;
}