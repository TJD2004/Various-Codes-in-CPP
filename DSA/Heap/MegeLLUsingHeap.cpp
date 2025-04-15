#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
    
    Node(int data) {
        this -> data = data;
        int next = NULL;
    }

    ~Node() {
        if(next != NULL) {
            delete next;
        }
    }
};

class compare {
    public:
        bool operator()(Node* a, Node* b) {
            return a -> data > b -> data;
        }
};

Node* mergeKLints(vector<Node*>&listArray) {

    priority_queue<vector<Node*>, vector<Node*>, compare> minHeap;

    int k = listArray.size();

    if(k == 0) 
        return NULL;

    for(int i=0; i < k; i++) {
        if(listArray[i] != NULL) {
            minHeap.push(listArray[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;
    while(minHeap.size() > 0) {
        Node* top = minHeap.top();
        minHeap.pop();

        if(top -> next != NULL) {
            minHeap.push(top -> next);
        }

        if(head == NULL) {
            head = top;
            tail = top;
        }
        else {
            tail->next = top;
            tail = top;
        }
    }
    return head;
}

int main() {
    Node* list1 = new Node(1);
    list1->next = new Node(4);
    list1->next->next = new Node(7);

    Node* list2 = new Node(2);
    list2->next = new Node(5);
    list2->next->next = new Node(8);

    Node* list3 = new Node(3);
    list3->next = new Node(6);
    list3->next->next = new Node(9);

    vector<Node*> listArray = {list1, list2, list3};

    Node* mergedList = mergeKLints(listArray);

    while(mergedList != NULL) {
        cout << mergedList->data << " ";
        mergedList = mergedList->next;
    }

    return 0;
}