#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor to initialize node
    Node(int d) {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Insert at head
void insertAtHead(Node*& head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    if (head != NULL) {
        head->prev = temp;
    }
    head = temp; // Update head to the new node
}

// Insert at tail
void insertAtTail(Node*& tail, int d) {
    Node* temp = new Node(d);
    if (tail == NULL) {
        tail = temp; // If list is empty, set both head and tail
    } else {
        tail->next = temp;
        temp->prev = tail; // Set the prev pointer of the new tail
        tail = temp; // Update the tail pointer
    }
}

// Print list
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

// Insert at a specific position
void insertAtPosition(Node*& head, Node*& tail, int position, int d) {
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) { // If we reach the end, insert at tail
        insertAtTail(tail, d);
        return;
    }

    // Create a new node to insert
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = nodeToInsert;
    }
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

// Reverse linked list
Node* ReverseLinkedList(Node* &head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        if (prev != NULL) {
            prev->prev = curr;
        }
        prev = curr;
        curr = forward;
    }

    head = prev;
    return head;
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Inserting elements at positions 1 to 5
    insertAtPosition(head, tail, 1, 10);
    insertAtPosition(head, tail, 2, 12);
    insertAtPosition(head, tail, 3, 14);
    insertAtPosition(head, tail, 4, 16);
    insertAtPosition(head, tail, 5, 18);

    cout << "Original list: ";
    print(head);

    head = ReverseLinkedList(head);

    cout << "Reversed list: ";
    print(head);

    return 0;
}
