#include <iostream>
#include <cstdlib>
#include <cmath>
#include "minheap.h"
using namespace std;

class ArrayMinHeap : public MinHeap {
    int* array;
    int size;
    int capacity;
    
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    int left(int n) {
        return (2 * n) + 1;
    }

    int right(int n) {
        return (2 * n) + 2;
    }
    
    int parent(int n) {
        return (n - 1) / 2;
    }
    
    void resizeArrayUp() {
        // Double the capacity, rounded up to nearest integer if needed
        capacity = (int) ceil(capacity * 1.5);
        array = (int*) realloc(array, capacity * sizeof(int));
    }
    
    void resizeArrayDown() {
        // Reduce the capacity to 80%, rounded up, ensuring a minimum capacity of 5
        capacity = (int) ceil(capacity * 0.8);
        if (capacity < 5) {
            capacity = 5;
        }
        array = (int*) realloc(array, capacity * sizeof(int));
    }
    
    void heapifyDown(int current) {
        while (true) {
            int leftChild = left(current);
            int rightChild = right(current);
            int smallest = current;
            
            if (leftChild < size && array[leftChild] < array[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < size && array[rightChild] < array[smallest]) {
                smallest = rightChild;
            }
            
            if (smallest == current) {
                break;
            }
            
            swap(array[current], array[smallest]);
            current = smallest;
        }
    }
    
public:
    ArrayMinHeap() {
        size = 0;
        capacity = 5;  // Initially set capacity to 5
        array = (int*) calloc(capacity, sizeof(int));
    }

    void insert(int num) {
        if (size == capacity) {
            resizeArrayUp();
        }
        
        array[size] = num;
        int current = size;
        
        // Bubble up to maintain heap property
        while (current > 0 && array[current] < array[(current - 1) / 2]) {
            swap(array[current], array[(current - 1) / 2]);
            current = (current - 1) / 2;
        }
        
        size++;
    }

    int removeMin() {
        if (size == 0) {
            return -1;
        }

        int minValue = array[0];
        array[0] = array[size - 1];
        size--;
        
        heapifyDown(0);
        
        // After removing, check if we need to reduce the array size
        if (size <= (int) ceil(capacity * 0.75)) {
            resizeArrayDown();
        }
        
        return minValue;
    }

    void print() {
        if (size == 0) {
            cout << "EMPTY" << endl;
            return;
        }

        cout << "Size: " << size << "/" << capacity << endl;
        cout << "TREE: " << endl;
        print_tree("", 0, false);

        cout << "ARRAY: ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void print_tree(string prefix, int n, bool isLeft) {
        cout << prefix;
        cout << (isLeft ? "+--L: " : "+--R: ");
        cout << array[n] << endl;
        
        if (left(n) < size) {
            print_tree(prefix + "|   ", left(n), true);
        }
        if (right(n) < size) {
            print_tree(prefix + "|   ", right(n), false);
        }
    }
};
