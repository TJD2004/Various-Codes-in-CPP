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


//Sorting 0s, 1s, 2s in linked list
// Approach 1
Node* sortList1(Node* head) {

    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    
    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == 0) {
            zeroCount++;
        }
        else if(temp->data == 1) {
            oneCount++;
        }
        else if(temp->data == 2) {
            twoCount++;
        }
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL) {
        if(zeroCount > 0) {
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount > 0) {
            temp->data = 1;
            oneCount--;
        }
        else if(twoCount > 0) {
            temp->data = 2;
            twoCount--;

        }
        temp = temp->next;
    }

    return head;
}

void populate(Node* tail, Node* curr){

    tail -> next = curr;
    tail = curr;
}


//Sorting 0s, 1s, 2s in linked list
// Approach 2
Node* sortList2(Node* head) {
    
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    while(curr != NULL) {
        int val = curr -> data;

        if(val == 0) {
            populate(zeroTail, curr);
        }

        else if(val == 1) {
            populate(oneTail, curr);
        }

        else if(val == 2) {
            populate(twoTail, curr);
        }

        curr = curr -> next;
    }

    
    //  merging 3 sublist
    //  1s list not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }

    else {
        //  1s list -> empty
        zeroTail -> next = twoHead -> next;
    }

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    //setup head
    head = zeroHead -> next;

    /*
    
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    */
   
    return head;
}


int main() {

    Node* head = NULL;
    Node* tail = NULL;

    // Inserting elements 0s, 1s, 2s at positions 1 to 11
    insertAtPosition(tail, head, 1, 1);
    insertAtPosition(tail, head, 2, 0);
    insertAtPosition(tail, head, 3, 2);
    insertAtPosition(tail, head, 4, 2);
    insertAtPosition(tail, head, 5, 1);
    insertAtPosition(tail, head, 6, 1);
    insertAtPosition(tail, head, 7, 0);
    insertAtPosition(tail, head, 8, 2);
    insertAtPosition(tail, head, 9, 0);
    insertAtPosition(tail, head, 10, 1);

    cout << "Original list: ";
    print(head);  // Print the original list

    head = sortList1(head);
    cout << "List After Sorting (Approach1): ";
    print(head);

    head = sortList2(head);
    cout << "List After Sorting (Approach2): ";
    print(head);

    

    return 0;
}