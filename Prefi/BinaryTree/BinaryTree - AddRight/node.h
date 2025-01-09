#include <iostream>
using namespace std;
struct node{
	int elem;
	node* left;
	node* right;
	node* parent;
	
	int depth(){
		if(!parent){
			return 0;
		}
		return 1 + parent->depth();
	}	
	
	int height(){
		if(!left && !right){
			return 0;
		}
		
		int leftHeight = (left ? left->height() : 0);
		int rightHeight = (right ? right->height() : 0);
		
/*
		int leftHeight, rightHeight;
		leftHeight = 0; rightHeight = 0;
		if(leftHeight != nullptr){
			leftHeight = left->height();
		}
		if(rightHeight != nullptr){
			rightHeight = right->height();
		}
*/		
		
		return 1 + max(leftHeight, rightHeight);
	}								
};