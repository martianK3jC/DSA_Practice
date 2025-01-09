// TODO change this to handle char elements
#include "stack.h"
#include <iostream>
#include "arraylist.h"
using namespace std;

class ArrayStack : public Stack {
	ArrayList* list = new ArrayList();
	public:

    // TODO push
	void push(char c) {
        list->add(c);
	}

    // TODO pop
	char pop() {
	    if(!isEmpty()){
            return list->removeLast();
	    } else{
	        return ' ';
	    }
	}

    // TODO top
	char top() {
        return list->get(list->size);
	}

    // TODO size
	int size() {
        return list->size;
	}

    // TODO isEmpty
	int isEmpty() {
        return list->_size() == 0;
	}

	void print() {
		list->print();
	}
};