#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor to initialize node with given data
    Node(int d) {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Insert node at the head of the list
void insertAtHead(Node*& head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    if (head != NULL) {
        head->prev = temp; // Update previous head's prev pointer
    }
    head = temp; // Update head to point to the new node
}

// Insert node at the tail of the list
void insertAtTail(Node*& tail, int d) {
    Node* temp = new Node(d);
    if (tail == NULL) {
        tail = temp; // If the list is empty, set both head and tail
    } else {
        tail->next = temp;
        temp->prev = tail; // Set the previous pointer of the new tail
        tail = temp; // Update the tail pointer
    }
}

// Print the entire list
void print(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " "; // Print data of the current node
        temp = temp->next; // Move to the next node
    }
    cout << endl;
}

// Insert node at a specific position in the list
void insertAtPosition(Node*& head, Node*& tail, int position, int d) {
    if (position == 1) {
        insertAtHead(head, d); // Insert at the beginning
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next; // Move to the node before the desired position
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
        temp->next->prev = nodeToInsert; // Update the previous pointer of the next node
    }
    temp->next = nodeToInsert; // Update the next pointer of the previous node
    nodeToInsert->prev = temp; // Set the prev pointer of the new node
}

Node* kReverse(Node* &head, int k) {

    // base case
    if(head == NULL) {
        return NULL;
    }

    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while(curr != NULL && count < k) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    //Recursion Call
    if(next != NULL) {
        head -> next = kReverse(next, k);
    }

    return prev;
}


int main() {

    Node* head = NULL;
    Node* tail = NULL;
     
    int k = 2;

    // Inserting elements at positions 1 to 6
    insertAtPosition(head, tail, 1, 10);
    insertAtPosition(head, tail, 2, 12);
    insertAtPosition(head, tail, 3, 14);
    insertAtPosition(head, tail, 4, 16);
    insertAtPosition(head, tail, 5, 18);
    insertAtPosition(head, tail, 6, 20);

    print(head);

    head = kReverse(head, k);

    print(head);

    return 0;
}