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
        insertAtTail(head, tail, d);
        return;
    }

    // Create a new node
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* add(Node* first, Node* second) {
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while (first != NULL || second != NULL || carry != 0) {
        int sum = carry;

        if (first != NULL) {
            sum += first->data;
            first = first->next;
        }
        if (second != NULL) {
            sum += second->data;
            second = second->next;
        }

        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
    }
    return ansHead;
}

Node* add2Lists(Node* first, Node* second) {
    // Reverse Linked Lists
    first = reverse(first);
    second = reverse(second);

    // Adding Two Linked Lists
    Node* ans = add(first, second);

    // Reverse ans
    ans = reverse(ans);

    return ans;  // Return the final result
}

int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;

    // list-1
    insertAtPosition(tail1, head1, 1, 1);
    insertAtPosition(tail1, head1, 2, 3);
    insertAtPosition(tail1, head1, 3, 5);
    insertAtPosition(tail1, head1, 4, 7);
    insertAtPosition(tail1, head1, 5, 9);

    cout << "Element in List-1 : ";
    print(head1);

    // list-2
    insertAtPosition(tail2, head2, 1, 2);
    insertAtPosition(tail2, head2, 2, 4);
    insertAtPosition(tail2, head2, 3, 6);
    insertAtPosition(tail2, head2, 4, 8);

    cout << "Element in List-2 : ";
    print(head2);

    // Add the two lists
    Node* ans = add2Lists(head1, head2);

    // Print the result of addition
    cout << "Sum of 2 Lists : ";
    print(ans);

    return 0;
}
