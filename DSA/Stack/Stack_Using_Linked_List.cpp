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
    Node* top; 

    Stack() {
        top = NULL; 
    }

    void push(int d) {
        Node* newNode = new Node(d);
        newNode->next = top; 
        top = newNode; 
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = top;  
        top = top->next; 
        delete temp;
    }


    int peek() {
        if (top != NULL) {
            return top->data;
        } else {
            cout << "Stack is empty" << endl;
            return -1; 
        }
    }

  
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
