#include "node.h"
class BinaryTree{
	public:
		virtual node* left(node*) = 0;
		virtual node* right(node*) = 0;
		virtual node* addLeft(int) = 0;
		virtual node* addRight(int) = 0;
		virtual int getRoot() = 0;
		virtual void print() = 0;
		//TRAVERSALS-----
		virtual void preorder() = 0;
		virtual void inorder() = 0;
		virtual void postorder() = 0;
		virtual void breadthfirst() = 0;
};