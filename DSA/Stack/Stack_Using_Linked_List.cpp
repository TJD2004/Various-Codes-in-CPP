#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
public:
    Node* top;  // Points to the top of the stack

    Stack() {
        top = NULL;  // Initialize an empty stack
    }

    // Push a new value onto the stack
    void push(int d) {
        Node* newNode = new Node(d);  // Create a new node with the given data
        newNode->next = top;  // Link the new node to the current top
        top = newNode;  // Update the top pointer to the new node
    }

    // Pop the top value from the stack
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = top;  // Store the current top node
        top = top->next;  // Update the top pointer to the next node
        delete temp;
    }

    // Peek at the top value of the stack
    int peek() {
        if (top != NULL) {
            return top->data;
        } else {
            cout << "Stack is empty" << endl;
            return -1; 
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    Stack st;

    st.push(25);  
    st.push(30); 

    cout << "Top element is: " << st.peek() << endl;  

    st.pop();  
    cout << "Top element after pop is: " << st.peek() << endl; 

    st.pop(); 
    st.pop();  

    return 0;
}
