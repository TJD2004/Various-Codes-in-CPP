#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    // Constructor
    Queue() {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    // Function to add an element to the queue
    void enqueue(int data) {
        Node* newNode = new Node(data);

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;  
            rear = newNode;        
        }
        size++;
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;  
        if (front == NULL) {
            rear = NULL; 
        }
        delete temp; 
        size--;
    }

    // Function to get the element at the front of the queue
    int getFront() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return -1; 
        }
        return front->data;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Function to get the size of the queue
    int getSize() {
        return size;
    }

    // Destructor to clean up memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();  
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.getFront() << endl;
    cout << "Queue size: " << q.getSize() << endl;    

    q.dequeue();
    cout << "Front element after dequeue: " << q.getFront() << endl; 
    cout << "Queue size after dequeue: " << q.getSize() << endl;  

    q.dequeue();
    q.dequeue();
    cout << "Queue empty: " << (q.isEmpty() ? "true" : "false") << endl;

    return 0;
}
