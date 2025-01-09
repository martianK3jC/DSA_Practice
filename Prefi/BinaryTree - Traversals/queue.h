#include "node.h"
class Queue{
	public:
		virtual void enqueue(node*) = 0;//addTail
		virtual node* dequeue() = 0;//removeHead
		virtual node* first() = 0;
		virtual int size() = 0;
		virtual bool isEmpty() = 0;
		virtual void print() = 0;
};