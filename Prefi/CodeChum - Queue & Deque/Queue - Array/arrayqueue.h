#include "queue.h"
#include "arraylist.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class ArrayQueue : public Queue {
	ArrayList list;
	
	public:
		void enqueue(int num){
			list->add(num);
		}
		
		int dequeue(){
			if(!isEmpty()){
				return list.removeFirst();
			}
			return 0;
		}
		
		int first(){
			if(!isEmpty()){
				//get: pos -1
				return list->get(1);
			}
		}
		
		int size(){
			return list->_size();
		}
		
		bool isEmpty(){
			return size() == 0;
		}
		
		void print(){
			list->print();
		}
		
		int removeLast(){
            if(isEmpty()){
                return list.removeLast();
            }
            return 0;
        }
};