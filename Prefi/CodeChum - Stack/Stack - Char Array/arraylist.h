// TODO change this to handle char elements
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "list.h"
using namespace std;

class ArrayList : public List {
    public:
    int* array;
    int size;
    int capacity = 5;

	void dynamic_add() {
		int new_size = ceil(capacity * 1.5);
		int* new_array = (int*) realloc(array, sizeof(int) * new_size);
		array = new_array;
		capacity = new_size;
	}

	void dynamic_deduce() {
		int new_size = ceil(capacity * 0.75);
		int* new_array = (int*) realloc(array, sizeof(int) * new_size);
		array = new_array;
		capacity = new_size;
	}

    public:
    // constructor
    ArrayList() {
    	array = (int*) calloc( capacity, sizeof(int) );
        size = 0;
    }

    void add(char letter) {
        // TODO add num
        array[size++] = letter;
        dynamic_add();
    }

    int _size() {
    	return size;
	}

    char removeLast() {
        // TODO remove and return last element
        array[size--];
        int count = 0;
        for(int i = 0; i < size; i++){
            count++;
        }
        dynamic_deduce();
        return array[count];
	}


	int removeFirst() {
        // NOT NECESSARY
        return 0;
    }

    int remove(int num) {
        // NOT NECESSARY
        return 0;
    }

    char get(int pos) {
        return array[pos-1];
    }

    void print() {
   		int i;
        for (i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        for (; i < capacity; i++) {
            cout << "? ";
		}
        cout << endl;
    }
};