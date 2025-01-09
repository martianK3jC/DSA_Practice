#include <iostream>
#include <cstdlib>
#include <math.h>
#include "list.h"
using namespace std;

class ArrayList : public List{
	int* array;
	int size;
	int capacity = 5;
	
	void dynamic_add(){
		int newSize = ceil(capacity * 1.5);
		array = (int*) realloc(array, sizeof(int) * newSize);
		capacity = newSize;
	}
	
	void dynamic_deduce(){
		int newSize = ceil(capacity * 0.75);
		array = (int*) realloc (array, sizeof(int) * newSize);
		capacity = newSize;
	}
	
	public:
		//CONSTRUCTOR
		ArrayList(){
			array = (int*) calloc(capacity, sizeof(int));
			size = 0;
		}
		
		void add(int num){
			if(size == capacity){
				dynamic_add();
			}
			array[size++];
		}
		
		int _size(){
			return size;
		}
		
		int removeLast{
			return array[size--];
		}
		
		inr removeFirst(){
			//Step 1: 
			int num = array[0];
			
			//Step 2: Move elements to the left
			for(int i = 0; i < size; i++){
				array[i] = array[i + 1];
			}
			
			//Step 3: set the size
			array[size-1] = 0;
			size -= 1;
			
			//Step 4: check to reduce capacity
			if(size <= 2.0/3 * capacity){
				dynamic_deduce();
			}
			
			//Step 5: Return
			return num;
			
		}
		
	    int remove(int num) {
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
	
	    int get(int pos) {
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
