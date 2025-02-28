#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

class Queue {
public:
    Node* top;
    Node* front;

    Queue() {
        top = NULL;
        front = NULL;
    }

    void push(int d) {
        Node* newNode = new Node(d);
        if (top == NULL) {
            top = front = newNode;
        } else {
            top->next = newNode;
            top = newNode;
        }
    }

    void pop() {
        if (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        } else {
            cout << "Queue is empty!" << endl;
        }
    }

    int peek() {
        if (front != NULL) {
            return front->data;
        } else {
            cout << "Queue is empty!" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return front == NULL;
    }
};

int main() {
    Queue q;

    q.push(5);
    q.push(10);

    cout << q.peek() << endl;

    q.pop();

    cout << q.peek() << endl; 

    q.push(15);

    cout << q.peek() << endl; 

    q.pop();
    q.pop();

    if (q.isEmpty()) {
        cout << "Queue is empty" << endl; 
    } else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}
