#include<iostream>
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
        cout << "Node Data: " << temp->data;
        if (temp->random)
            cout << ", Random Data: " << temp->random->data;
        else
            cout << ", Random Data: NULL";
        cout << endl;
        temp = temp->next;
    }
    cout << endl;
}

// Optimized Clone function
Node* cloneList(Node* head) {
    if (head == NULL) return NULL;

    Node* temp = head;

    // Step 1: Clone the nodes and insert them next to the original nodes
    while (temp != NULL) {
        Node* cloneNode = new Node(temp->data);
        cloneNode->next = temp->next;
        temp->next = cloneNode;
        temp = cloneNode->next;
    }

    // Step 2: Set the random pointers of the cloned nodes
    temp = head;
    while (temp != NULL) {
        if (temp->random != NULL)
            temp->next->random = temp->random->next;
        temp = temp->next->next;
    }

    // Step 3: Separate the cloned list from the original list
    Node* clonedHead = head->next;
    Node* original = head;
    Node* cloned = clonedHead;
    while (original != NULL) {
        original->next = original->next->next;
        if (cloned->next != NULL)
            cloned->next = cloned->next->next;
        original = original->next;
        cloned = cloned->next;
    }

    return clonedHead;
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
    cout << "Original List: " << endl;
    print(head);

    // Clone the list
    Node* clonedList = cloneList(head);
    cout << "Cloned List: " << endl;
    print(clonedList);

    return 0;
}
