#include <iostream>
#include "minheap.h"
#include "arrayminheap.h"
using namespace std;

int main() {
    ArrayMinHeap heap;
    char operation;
    int value;

    while (true) {
        cout << "Op: ";
        cin >> operation;

        if (operation == 'i') { // Insert operation
            cin >> value;
            heap.insert(value);
        } else if (operation == 'p') { // Print operation
            heap.print();
        } else if (operation == 'r') { // Remove minimum operation
            int removed = heap.removeMin();
            if (removed != -1) {
                cout << "Removed " << removed << endl;
            } else {
                cout << "Heap is empty, nothing to remove." << endl;
            }
        } else if (operation == 'x') { // Exit operation
            cout << "Exiting" << endl;
            break;
        } else {
            cout << "Invalid operation." << endl;
        }
    }

    return 0;
}
