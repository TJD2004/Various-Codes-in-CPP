#include <iostream>
using namespace std;

class Deque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if (isFull()) {
            return false;
        }
        else if (isEmpty()) {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1) {
            front = size - 1;
        }
        else {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if (isFull()) {
            return false;
        }
        else if (isEmpty()) {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if (isEmpty()) {
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

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if (isEmpty()) {
            return -1;
        }
        
        int ans = arr[rear];
        arr[rear] = -1;
        
        if (front == rear) { // Single element is present
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = size - 1; // To maintain cyclic nature
        }
        else { // Normal flow
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        return (front == -1);
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        return ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)));
    }

    // Destructor to free dynamically allocated memory
    ~Deque()
    {
        delete[] arr;
    }
};


int main()
{
    Deque dq(5);

    cout << "Push front 10: " << (dq.pushFront(10) ? "Success" : "Failed") << endl;
    cout << "Push rear 20: " << (dq.pushRear(20) ? "Success" : "Failed") << endl;
    cout << "Push front 5: " << (dq.pushFront(5) ? "Success" : "Failed") << endl;
    cout << "Push rear 30: " << (dq.pushRear(30) ? "Success" : "Failed") << endl;
    cout << "Push front 1: " << (dq.pushFront(1) ? "Success" : "Failed") << endl;

    cout << "Push rear 40: " << (dq.pushRear(40) ? "Success" : "Failed") << endl;

    cout << "Pop front: " << dq.popFront() << endl;
    cout << "Pop rear: " << dq.popRear() << endl;

    cout << "Push rear 50: " << (dq.pushRear(50) ? "Success" : "Failed") << endl;

    cout << "Front: " << dq.getFront() << endl;
    cout << "Rear: " << dq.getRear() << endl;

    cout << "Pop front: " << dq.popFront() << endl;
    cout << "Pop front: " << dq.popFront() << endl;
    cout << "Pop front: " << dq.popFront() << endl;
    cout << "Pop front: " << dq.popFront() << endl;
    cout << "Pop front: " << dq.popFront() << endl;

    return 0;
}
