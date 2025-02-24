#include <iostream>
#include <vector>
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
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node*& head, Node*& tail, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
    if (tail == NULL) {
        tail = head;
    }
}

void insertAtTail(Node*& tail, int d) {
    Node* temp = new Node(d);
    if (tail == NULL) {
        tail = temp;
        return;
    }
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

void insertAtPosition(Node*& head, Node*& tail, int position, int d) {
    if (position == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }

    if (temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

bool checkPalindrome(vector<int> arr) {
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
        if (arr[start] != arr[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool isPalindrome1(Node* head) {
    vector<int> arr;
    Node* temp = head;
    while (temp != NULL) {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return checkPalindrome(arr);
}

Node* getMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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

bool isPalindrome2(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    Node* middle = getMid(head);
    Node* temp = middle->next;
    middle->next = reverse(temp);

    Node* head1 = head;
    Node* head2 = middle->next;

    while (head2 != NULL) {
        if (head2->data != head1->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    temp = middle->next;
    middle->next = reverse(temp);

    return true;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtPosition(head, tail, 1, 10);
    insertAtPosition(head, tail, 2, 12);
    insertAtPosition(head, tail, 3, 14);
    insertAtPosition(head, tail, 4, 12);
    insertAtPosition(head, tail, 5, 10);

    cout << "List: ";
    print(head);

    if (isPalindrome1(head)) {
        cout << "List is Palindrome (Approach 1)" << endl;
    } else {
        cout << "List is not Palindrome (Approach 1)" << endl;
    }

    if (isPalindrome2(head)) {
        cout << "List is Palindrome (Approach 2)" << endl;
    } else {
        cout << "List is not Palindrome (Approach 2)" << endl;
    }

    return 0;
}