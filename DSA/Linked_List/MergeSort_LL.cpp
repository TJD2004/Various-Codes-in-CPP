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
        // Memory cleanup
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
};

void insertAtHead(Node* &head, Node* &tail, int d) {
    // new node create
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
    
    // If list was empty, head and tail will both point to the new node
    if (head->next == NULL) {
        tail = head;
    }
}

void insertAtTail(Node* &tail, int d) {
    // new node create
    Node* temp = new Node(d);
    if(tail != NULL) {
        tail->next = temp;
    }
    tail = temp;
}

void print(Node* &head) {
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

void insertAtPosition(Node* &tail, Node* &head, int position, int d) {
    // Insert at Start (position 1)
    if(position == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    // Traverse to the position just before the insertion point
    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    // Insert at Last Position (if temp->next == NULL)
    if(temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    // Create a new node for the data
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;

    Node* ans = new Node(-1);
    Node* temp = ans;

    // Merge 2 sorted Linked Lists
    while(left != NULL && right != NULL) {
        if(left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

Node* mergeSort(Node *head, Node* &tail) {
    // Base case
    if(head == NULL || head->next == NULL) {
        tail = head;
        return head;
    }

    // Break the linked list into 2 halves
    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    // Recursive calls to sort both halves
    left = mergeSort(left, tail);
    right = mergeSort(right, tail);

    // Merge both halves
    Node* result = merge(left, right);

    // Find the new tail after merging
    tail = result;
    while(tail->next != NULL) {
        tail = tail->next;
    }

    return result;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Insert elements using insertAtPosition
    insertAtPosition(tail, head, 1, 10);  // Insert 10 at position 1 (head)
    insertAtPosition(tail, head, 2, 20);  // Insert 20 at position 2
    insertAtPosition(tail, head, 3, 30);  // Insert 30 at position 3
    insertAtPosition(tail, head, 5, 5);   // Insert 5 at position 5
    insertAtPosition(tail, head, 6, 50);  // Insert 50 at position 6
    insertAtPosition(tail, head, 7, 40);  // Insert 40 at position 7

    // Print the current list
    cout << "Original List: ";
    print(head);  // Should print: 10 20 30 5 50 40

    // Perform Merge Sort
    head = mergeSort(head, tail);  // Sorting the list using merge sort

    cout << "Sorted List: ";
    print(head);  // Sorted List should be: 5 10 20 30 40 50

    return 0;
}
