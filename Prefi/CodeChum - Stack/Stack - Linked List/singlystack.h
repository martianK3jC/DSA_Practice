#include "stack.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class SinglyStack : public Stack{
	LinkedList* list;
	
	public:
	SinglyStack(){
		list = new LinkedList();
	}
	
	void push(int num){
		list->addHead(num);
	}
	
	int pop(){
		if(!isEmpty()){
			list->removeHead();
		}else{
			return 0;
		}
		
	}
	
	int size(){
		return list->getSize();
	}
	
	int top(){
		return list->getHead();
	}
	
	bool isEmpty(){
		return size() == 0;
	}
	
	void print(){
		list->print();
	}		
		
};