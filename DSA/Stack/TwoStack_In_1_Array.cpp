#include<iostream>
using namespace std;

class TwoStack {

    public:
    int *arr;
    int top1;
    int top2;
    int size;

    TwoStack(int size) {
        
        this -> size = size; 
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    void push1(int element) {
        
        if(top2- top1 > 1) {
            top1++;
            arr[top1] = element;
        }
        else {
            cout << "Stack Overflow" << endl;
        }
        
    }

    void push2(int element) {

        if(top2 - top1 > 1) {
            top2--;
            arr[top2] = element;
        }
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop1() {

        if(top1 >= 0) {
            int ans = arr[top1];
            top1--;
        }
    }

    void pop2() {

        if(top2 < size) {
            int ans = arr[top2];
            top2++;
        }
    }

    int peek1() {
        if(top1 >= 0)
            return arr[top1];
        
        else {
            cout << "Stack is Empty" << endl;
        }
    }

    int peek2() {
        if(top2 < size)
            return arr[top2];
        
        else {
            cout << "Stack is Empty" << endl;
        }
    }
};


int main() {

    TwoStack st1(5);
    TwoStack st2(5);

    st1.push1(24);
    st1.push1(33);
    st1.push1(45);
    st1.push1(64);
    st1.push1(46);

    cout << st1.peek1() << endl;

    st1.pop1();

    cout << st1.peek1() << endl;

    st2.push2(2);
    st2.push2(3);
    st2.push2(5);
    st2.push2(6);
    st2.push2(4);

    cout << st2.peek2() << endl;

    st2.pop2();

    cout << st2.peek2() << endl;

    return 0;
}