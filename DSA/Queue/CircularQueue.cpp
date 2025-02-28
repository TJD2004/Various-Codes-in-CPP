#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;
    
public:
    // Constructor to initialize the circular queue
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value) {
        // Check if the queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            return false;
        }
        else if (front == -1) { // First element to push
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0) {
            rear = 0; // To maintain cyclic nature
        }
        else { // Normal flow
            rear++;
        }
        // Push inside the queue
        arr[rear] = value;
        return true;
    }

    // Dequeues the top element from the queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue() {
        if (front == -1) { // To check if the queue is empty
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear) { // Single element is present
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0; // To maintain cyclic nature
        }
        else { // Normal flow
            front++;
        }
        return ans;
    }

    // Function to get the front element of the queue
    int getFront() {
        if (front == -1) return -1; // If queue is empty
        return arr[front];
    }

    // Function to get the rear element of the queue
    int getRear() {
        if (rear == -1) return -1; // If queue is empty
        return arr[rear];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Function to check if the queue is full
    bool isFull() {
        return ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)));
    }

    // Destructor to free dynamically allocated memory
    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
   
    CircularQueue q(5);

  
    cout << "Enqueue 10: " << (q.enqueue(10) ? "Success" : "Failed") << endl;
    cout << "Enqueue 20: " << (q.enqueue(20) ? "Success" : "Failed") << endl;
    cout << "Enqueue 30: " << (q.enqueue(30) ? "Success" : "Failed") << endl;
    cout << "Enqueue 40: " << (q.enqueue(40) ? "Success" : "Failed") << endl;
    cout << "Enqueue 50: " << (q.enqueue(50) ? "Success" : "Failed") << endl;
    
    // Try to enqueue an element when the queue is full
    cout << "Enqueue 60: " << (q.enqueue(60) ? "Success" : "Failed") << endl;

    // Dequeue elements
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;

    // Enqueue more elements
    cout << "Enqueue 60: " << (q.enqueue(60) ? "Success" : "Failed") << endl;
    cout << "Enqueue 70: " << (q.enqueue(70) ? "Success" : "Failed") << endl;

    // Dequeue all elements
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;

    // Check if the queue is empty
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
