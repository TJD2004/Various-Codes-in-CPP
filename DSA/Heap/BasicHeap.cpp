#include<iostream>
using namespace std;

/* Positions: 
        Node* : ith index;
        Parent : (i-1)/2;
        Left Child : 2*i + 1;
        Right Child : 2*i + 2;
*/

class heap {
public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {

        int index = size;
        arr[index] = val;
        size++;

        while(index > 0) {
            int parent = (index - 1) / 2;
            if(arr[parent] > arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void deleteAtNode() {
        
        if(size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }

        arr[0] = arr[size-1];
        size--;

        heapify(arr, size, 0);
    }

    void heapify(int arr[], int n, int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if(right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if(largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n) {
        
        int size = n;

        while(size > 0) {
            swap(arr[0], arr[size-1]);
            size--;
            heapify(arr, size, 0);
        }
    }
};

void print(heap h) {
    for(int i=0; i<h.size; i++) {
        cout << h.arr[i] << " ";
    }
}

int main() {
    
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);
    h.insert(60);
    h.insert(70);

    print(h);
    cout << endl;   

    h.deleteAtNode();
    print(h);
    cout << endl;

    h.heapify(h.arr, h.size, 0);
    print(h);

    return 0;
}



    

