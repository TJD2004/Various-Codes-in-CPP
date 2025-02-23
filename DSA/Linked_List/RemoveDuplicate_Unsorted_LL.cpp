#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;
        // Free memory
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
};

void insertAtHead(Node*& head, Node*& tail, int d) {
    // Create a new node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;

    // If the list was empty, update the tail
    if (tail == NULL) {
        tail = temp;
    }
}

void insertAtTail(Node*& tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(Node*& tail, Node*& head, int position, int d) {
    // Insert at the start
    if (position == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    // Inserting at the last position
    if (temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    // Create a new node
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}


// Remove Duplicate from the UnSorted Linked List
Node* removeDuplicate(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* curr = head;

    while (curr != NULL) {
        Node* temp = curr->next;
        Node* prev = curr;  // To track the previous node

        while (temp != NULL) {
            if (curr->data == temp->data) {
                // Duplicate found, remove temp
                prev->next = temp->next; // Link the previous node to the next of temp
                temp = prev->next;  // Move temp to the next node
            } else {
                prev = temp;  // Move prev to temp
                temp = temp->next;  // Move temp to the next node
            }
        }

        curr = curr->next;  // Move curr to the next node
    }

    return head;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Inserting elements in UnSorted Order at positions 1 to 11
    insertAtPosition(tail, head, 1, 1);
    insertAtPosition(tail, head, 2, 4);
    insertAtPosition(tail, head, 3, 3);
    insertAtPosition(tail, head, 4, 5);
    insertAtPosition(tail, head, 5, 9);
    insertAtPosition(tail, head, 6, 4);
    insertAtPosition(tail, head, 7, 2);
    insertAtPosition(tail, head, 8, 5);
    insertAtPosition(tail, head, 9, 10);
    insertAtPosition(tail, head, 10, 9);
    insertAtPosition(tail, head, 11, 7);

    cout << "Original list: ";
    print(head);  // Print the original list

    head = removeDuplicate(head);
    cout << "List after removal of duplicates: ";
    print(head);  // Print the list after duplicates are removed

    return 0;
}
