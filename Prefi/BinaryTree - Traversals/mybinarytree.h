#include <cstdlib>
#include <iostream>
#include "binarytree.h"
#include "arrayqueue.h"
using namespace std;

class MyBinaryTree : public BinaryTree{
	node* root;
	int size;
	
	node* create_node(node* parent, int elem){
		node* newNode = new node();
		newNode->elem = elem;
		newNode->parent = parent;
		newNode->left = nullptr;
		newNode->right = nullptr;
		size++;
		return newNode;
	}
	
	public:
		node* addRoot(int elem){
			if(root != null){
				throw logic_error("Already has root");
			}else{
				root = create_node(nullptr, elem);
			}
			return root;
		}
		
		node* left(node* parent){
			//getLeft node child
			return parent->left;
		}
		
		node* right(node* parent){
			return parent->right;
		}
		
		//TRAVERSAL METHODS
		void preorderTraversal(node* n){
			if(n != nullptr){
				//COUT. LEFT, RIGHT or vlr
				cout<<n->elem<<" ";
				preorderTraversal(n->left);
				preorderTraversal(n->right);	
			}
		}
		
		void preorder(){
			preorderTraversal(root);
		}
		
		void inorderTraversal(node* n){
			//LVR
			if(root != nullptr){
				inorderTraversal(n->left);
				cout<<n->elem<<" ";
				inorderTraversal(n->right);
			}
		}
		
		void inorder(){
			inorderTraversal(root);
		}
		
		void postorderTraversal(node* n){
			if(root != nullptr){
				//LRV
				postorderTraversal(n->left);
				postorderTraversal(n->right);
				cout<<n->elem<<" ";
			}
		}
		
		void postorder(){
			postorderTraversal(root);
		}
		
		void breadthfirst(){
			if(root == nullptr){
				return;
			}
			
			ArrayQueue queue;
			queue.enqueue(root);//addTail/addLast
			
			while(!queue.isEmpty()){
				node* current = queue.dequeue();//returns the node of removeFirst 
				cout<<current->elem<<" ";
				
				if(current->left != nullptr){
					queue.enqueue(current->left);
				}
				if(current->right != nullptr){
					queue.enqueue(current->left);
				}
			}
		}
		
		node* addLeft(node* n, int e){
			if(n->left){
				throw logic_error(to_string(n->elem + " already has a left child"));
			}
			n->left = create_node(n, e);
			return n->left;
		}
		
		node* addRight(node* n, int e){
			if(n->right){
				throw logic_error(to_string(n->elem) + " already has a right child");
			}
			n->right = create_node(n, e);
			return n->right;
		}
		
		void print() {
			cout << "Size: " << size << endl;
			if (!root) {
				cout << "EMPTY" << endl;
				return;
			}
			node* curr = root;
			print_node("", root, false);
	        cout << "Status: " << check_parent(root, NULL) << endl;
		}
	
		void print_node(string prefix, node* n, bool isLeft) {
			cout << prefix;
	        cout << (isLeft ? "+--L: " : "+--R: " );
	        cout << n->elem << endl;
			if (n->left) {
				print_node(prefix + "|   ", n->left, true);
			}
			if (n->right) {
				print_node(prefix + "|   ", n->right, false);
			}
		}
	
	    bool check_parent(node* curr, node* par) {
	        if (!curr) {
	            return true;
	        }
	        if (curr->parent != par) {
	            cout << "Illegal parent of " << curr->elem << ": " << curr->parent << " -- must be " << par << endl;
	            return false;
	        }
	        return check_parent(curr->left, curr) && check_parent(curr->right, curr);
	    }
};