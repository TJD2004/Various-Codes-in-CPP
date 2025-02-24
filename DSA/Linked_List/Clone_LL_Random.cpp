#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;
        // Memory cleanup
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
};

void insertAtTail(Node*& head, Node*& tail, int d) {
    Node* temp = new Node(d);
    if (tail == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void print(Node* head) {
    if(head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* cloneList(Node* head) {
    if (head == NULL) return NULL;

    Node* temp = head;
    unordered_map<Node*, Node*> oldToNewNode;

    // Step 1: Create the clone nodes and store them in the map
    while (temp != NULL) {
        Node* cloneNode = new Node(temp->data);
        oldToNewNode[temp] = cloneNode;
        temp = temp->next;
    }

    temp = head;
    // Step 2: Set next and random pointers for the cloned nodes using the map
    while (temp != NULL) {
        Node* cloneNode = oldToNewNode[temp];
        cloneNode->next = oldToNewNode[temp->next]; // Set the next pointer
        cloneNode->random = oldToNewNode[temp->random]; // Set the random pointer
        temp = temp->next;
    }

    // Return the head of the cloned list
    return oldToNewNode[head];
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Create a sample list
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 12);
    insertAtTail(head, tail, 14);
    insertAtTail(head, tail, 16);
    insertAtTail(head, tail, 18);

    // Manually set random pointers for the original list
    head->random = head->next->next; // 10 -> random points to 14
    head->next->random = head; // 12 -> random points to 10
    head->next->next->random = head->next->next->next; // 14 -> random points to 16
    head->next->next->next->random = head->next->next; // 16 -> random points to 14
    head->next->next->next->next->random = head->next->next->next; // 18 -> random points to 16

    // Original List
    cout << "Original List: ";
    print(head);

    // Clone the list
    Node* clonedList = cloneList(head);
    cout << "Cloned List: ";
    print(clonedList);

    return 0;
}
