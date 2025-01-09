#include <iostream>
#include <cstdlib>
#include <math.h>
#include "list.h"
using namespace std;

class ArrayList : public List{
	node** array;
	int size;
	int capacity;
	
	void dynamic_add()
	void dynamic_deduce()
	
	public:
		ArrayList(){
			array = (int*) calloc (capacity, sizeof(int));
			size = 0;
		}
		
		void add(node* num){//addLast
			if(size == capacity){
				dynamic_add();
			}
			array[size++] = num;
		}
		
		int _size(){
			return size;
		}
		
		node* removeLast(){
			return array[size--];
		}
		
		node* removeFirst(){
			node* n = array[0];//head
			
			for(int i = 0; i < size - 1; i++){
				array[i] = array[i+1];
			}
			
			array[size-1] = 0;
			size--;
			
			if(size <= 2.0/3 * capacity){
				dynamic_deduce();
			}
			
			return n;
		}
		
		int remove(node* num) {
        // Step 1: FIND the num
        for (int i = 0; i < size; i++) {
            if (array[i] == num) {
                // Step 2: MOVE the elements to left
                for (int j = i; j < size-1; j++) {
                    array[j] = array[j+1];
                }
                // Step 3: Set the size
                array[size-1] = 0;
                size = size-1;
                // Step 4: Check to reduce capacity
                if (size <= 2.0/3 * capacity) {
                	dynamic_deduce();
				}
                // Step 5: Return
                return i+1;
            }
        }
        return -1;
    }
		node* get(int pos){
			return array[pos-1];
		}
		void print(){
			int i;
			for(i = 0; i < size; i++){
				cout<<array[i]->elem<<" ";
			}
			for(;i < capacity; i++){
				cout<<"?";
			}
			cout<<endl;
		}
};