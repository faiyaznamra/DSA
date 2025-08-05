#include <iostream>
using namespace std;

class MaxHeap {
    int *heap;
    int capacity;
    int size;

public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[cap];
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    // Insert a new key
    void insert(int val) {
        if (size == capacity) {
            cout << "Heap is full!\n";
            return;
        }

        size++;
        int i = size - 1;
        heap[i] = val;

        // Fix max heap property
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Heapify a subtree at index i
    void heapify(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && heap[l] > heap[largest])
            largest = l;
        if (r < size && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    // Delete root (max element)
    void deleteRoot() {
        if (size <= 0) {
            cout << "Heap is empty!\n";
            return;
        }

        cout << "Deleted: " << heap[0] << endl;

        heap[0] = heap[size - 1];
        size--;
        heapify(0);
    }

    // Display heap as array
    void display() {
        cout << "Heap array: ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }

    ~MaxHeap() {
        delete[] heap;
    }
};
int main() {
    MaxHeap h(10);

    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(5);
    h.insert(10);

    h.display();       // Heap: 30 15 20 5 10

    h.deleteRoot();    // Deletes 30
    h.display();       // Heap: 20 15 10 5

    return 0;
}
