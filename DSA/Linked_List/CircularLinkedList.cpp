#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // Constructor to initialize the node with a given value
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    // Destructor to free memory of the node and its next nodes
    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

// Function to insert a node after a specified element
void insertNode(Node* &tail, int element, int d) {
    // If the list is empty, create the first node
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;  // Point to itself (circular)
    }
    else {
        Node* curr = tail;
        bool elementFound = false;

        // Traverse the list to find the element
        do {
            if(curr->data == element) {
                elementFound = true;
                break;
            }
            curr = curr->next;
        } while(curr != tail);

        // If element is not found, display an error and return
        if(!elementFound) {
            cout << "Element " << element << " not found in the list!" << endl;
            return;
        }

        // Create and insert the new node after the specified element
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

// Function to print the nodes in the circular linked list
void print(Node* tail) {
    // If the list is empty, show a message
    if(tail == NULL) {
        cout << "List is Empty" << endl;
        return;
    }

    Node* temp = tail;
    do {
        cout << tail->data << " ";  // Print node data
        tail = tail->next;
    } while(tail != temp);  // Loop until the list circles back

    cout << endl;
}

// Function to delete a node with a given value from the list
void deleteNode(Node* &tail, int value) {
    // If the list is empty, show a message
    if(tail == NULL) {
        cout << "List is empty, please check again" << endl;
        return;
    }

    Node* prev = tail;
    Node* curr = prev->next;

    // Traverse the list to find the node to delete
    while(curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    // Remove the node from the list
    prev->next = curr->next;

    // Update tail if the deleted node was the only node or the tail itself
    if(curr == prev) {
        tail = NULL;  // List becomes empty
    }
    else if(tail == curr) {
        tail = prev;  // Move tail to the previous node
    }

    // Free the memory of the deleted node
    curr->next = NULL;
    delete curr;
}

// Function to check if the linked list is circular
bool isCircularList(Node* head) {
    // If the list is empty, it's considered circular
    if(head == NULL) {
        return true;
    }

    Node* temp = head->next;
    while(temp != NULL && temp != head) {  // Traverse until we circle back to head
        temp = temp->next;
    }

    return temp == head;  // If we circle back to head, it's circular
}

int main() {
    Node* tail = NULL;  // Initialize the list as empty

    insertNode(tail, 5, 7);  // Insert 7 after 5
    print(tail);

    insertNode(tail, 7, 9);  // Insert 9 after 7
    print(tail);

    insertNode(tail, 5, 6);  // Insert 6 after 5
    print(tail);

    insertNode(tail, 9, 10);  // Insert 10 after 9
    print(tail);

    insertNode(tail, 3, 4);  // Insert 4 after 3
    print(tail);

    // Check if the list is circular and print the result
    if(isCircularList(tail)) {
        cout << "Linked List is Circular in nature" << endl;
    }
    else {
        cout << "Linked List is not Circular" << endl;
    }

    return 0;
}
