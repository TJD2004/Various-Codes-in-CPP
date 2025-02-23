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

Node* solve(Node* first, Node* second) {


    if(first -> next == NULL){
        first -> next = second;
        return first;
    }

    Node* curr1 = first;
    Node* next1 = curr1 -> next;
    Node* curr2 = second;
    Node* next2 = curr2 -> next;

    while(next1 != NULL && curr2 != NULL) {
        if(curr2 -> data >= curr1-> data && curr2 -> data <= next1 -> data) {
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;

            curr1 = curr2;
            curr2 = next2;
        }

        else {
            curr1 = curr1 -> next;
            next1 = next1 -> next;

            if(next1 == NULL) {
                curr1 -> next = curr2;
                return first;
            }
        }
    }
}


Node* sortTwoList(Node* first, Node* second) {

    if(first == NULL) 
        return second;

    if(second == NULL) 
        return first;

    if(first -> data <= second -> data) {
        solve(first, second);
    }

    else {
        solve(second, first);
    }

}

int main() {
    
    Node* head = NULL;
    Node* head1 = NULL;
    Node* tail1 = NULL;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    // Inserting elements in Sorted Order
    // list-1
    insertAtPosition(tail1, head1, 1, 1);
    insertAtPosition(tail1, head1, 2, 3);
    insertAtPosition(tail1, head1, 3, 5);
    insertAtPosition(tail1, head1, 4, 7);
    insertAtPosition(tail1, head1, 5, 9);

    // list-2
    insertAtPosition(tail2, head2, 1, 2);
    insertAtPosition(tail2, head2, 2, 4);
    insertAtPosition(tail2, head2, 3, 6);
    insertAtPosition(tail2, head2, 4, 8);
    insertAtPosition(tail2, head2, 5, 10);

    cout << "Original list-1 : ";
    print(head1);  // Print the original list-1

    cout << "Original list-2 : ";
    print(head2);  // Print the original list-2

    head = sortTwoList(head1, head2);
    cout << "List after Sort & Merge two list : " ;
    print(head);
    
    return 0;
}