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

// Recursive helper function to reverse the list
void reverse(Node*& head, Node* curr, Node* prev) {
    if (curr == NULL) {
        head = prev; // After the last node, update head to point to the new head
        return;
    }

    Node* forward = curr->next; // Save the next node
    curr->next = prev; // Reverse the next pointer
    curr->prev = forward; // Reverse the prev pointer
    reverse(head, forward, curr); // Recur with the next node
}

// Wrapper function to reverse the entire linked list
Node* ReverseLinkedListRecursive(Node*& head) {
    Node* curr = head;
    Node* prev = NULL;
    reverse(head, curr, prev); // Start the recursion to reverse the list
    return head; // Return the new head of the reversed list
}

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
    print(head); // Print the original list

    head = ReverseLinkedListRecursive(head); // Reverse the list

    cout << "Reversed list: ";
    print(head); // Print the reversed list

    return 0;
}
