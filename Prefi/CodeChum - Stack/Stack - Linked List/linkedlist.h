#include "list.h"
#include<iostream>
#include "node.h"
#include <cstdlib>
using namespace std;

class LinkedList : public List{
	node* head;
	node* tail;
	int size = 0;
	
	public:
		void addHead(int num){
			node* newNode = new node();
			newNode->elem = num;
			if(size == 0){
				head = tail = newNode;
			}else{
				newNode->next = head;
				head = newNode;
			}
			size++;
		}
		
		int removeHead(){
			int removedHead = head->elem;
			head = head->next;
			size--;
			return removedHead;
		}
		
		int getHead(){//getHead
			return head->elem;
		}
		
		int getSize(){
			return size;
		}
		
		void print(){
			node* curr = head;
			if(size == 0){
				cout<<"Empty"<<endl;
			} else {
				while(curr){
					cout<<curr->elem;
					if(curr->next){
						cout<<" -> ";
					}else{
						cout<<endl;
					}
					curr = curr->next;
				}
			}
		}
};