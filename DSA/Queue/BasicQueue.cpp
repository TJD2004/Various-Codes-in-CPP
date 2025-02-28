#include<iostream>
using namespace std;

class Queue {
public:
    int *arr;
    int front;
    int top;
    int size;

    // Constructor to initialize the queue
    Queue(int size) {
        this->size = size;
        arr = new int[size];
        top = -1; 
        front = 0; 
    }

    // Push operation: Add an element to the queue
    void push(int d) {
        if (top == size - 1) {
            cout << "Queue is full!" << endl;
        } else {
            top++;
            arr[top] = d;  
        }
    }

    // Pop operation: Remove the element from the front of the queue
    void pop() {
        if (front > top) {  
            cout << "Queue is empty!" << endl;
        } else {
            front++; 
        }
    }

    // Peek operation: Return the front element of the queue
    int peek() {
        if (front > top) { 
            cout << "Queue is empty!" << endl;
            return -1;  
        }
        return arr[front]; 
    }

    bool isEmpty() {
        return (front > top); 
    }

};

int main() {

    Queue q(5);  
    q.push(5);
    q.push(4);

    cout << "Peek after pushing 5 and 4: " << q.peek() << endl;

    q.pop(); 

    cout << "Peek after popping one element: " << q.peek() << endl;

    q.push(6);
    q.push(8);

    cout << "Peek after pushing 6 and 8: " << q.peek() << endl; 

    q.pop();  

    cout << "Peek after popping another element: " << q.peek() << endl; 

    if (q.isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    q.pop();  

    if (q.isEmpty()) {
        cout << "Queue is empty" << endl;  
    } else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}
