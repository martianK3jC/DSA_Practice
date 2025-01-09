#include <cstdlib>
#include <iostream>
#include "binarytree.h"
using namespace std;

class MyBinaryTree : public BinaryTree {
    node* root;
    int size;

    node* create_node(int num, node* parent) {
        node* newNode = new node();
        newNode->elem = num;
        newNode->parent = parent;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

public:
    MyBinaryTree() {
        root = nullptr;
        size = 0;
    }

    node* addRoot(int num) override {
        if (root) {
            throw logic_error("Already has root");
        } else {
            root = create_node(num, nullptr);
            size++;
        }
        return root;
    }

    node* left(node* n) override {
        if (!n) return nullptr;
        return n->left;
    }

    node* right(node* n) override {
        if (!n) return nullptr;
        return n->right;
    }

    node* addLeft(node* parent, int num) override {
        if (parent->left) {
            throw logic_error(to_string(parent->elem) + " already has a left child");
        }
        parent->left = create_node(num, parent);
        size++;
        return parent->left;
    }

    node* addRight(node* parent, int num) override {
        if (parent->right) {
            throw logic_error(to_string(parent->elem) + " already has a right child");
        }
        parent->right = create_node(num, parent);
        size++;
        return parent->right;
    }

    node* sibling(node* n) override {
        if (!n || !n->parent) {
            return nullptr;
        }
        if (n == n->parent->left) {
            return n->parent->right;
        } else {
            return n->parent->left;
        }
    }
    
    int remove(node* n){
    	if(!n){
    		throw logic_error("Cannot remove a null node");
		}
		
		int removedElem = n->elem;
		
		//case 1: if the node is root
		if(n == root){
			if(!root->left && !root->right){//if root has no left and right
				delete root;
				root = nullptr;
			}else if(root->depth() && root->right){//if node has both chilren
				throw logic_error("Cannot remove " + to_string(root->elem) + "for it as 2 children"));
			}else{//if root only has a child
				root = (root->left) ? root->left : root->right;//the only child becomes the root
				root->parent = nullptr;//root parent(prev root) gets nullified
				delete n;
			}
			size--;
			return removedElem;
		}
		
		//Case 2:
		if(n->left && n->right){//if the node has 2 children
			throw logic_error("Cannot remmove " + to_string(n->elem) + " for it has 2 children")
		}
		
		//Case 3: Check if the node `n` has no children (leaf node).
		if(!n->left && !n->right){
			if(n == n->parent->left){
			//If `n` is the left child of its parent, set the parent's left pointer to `NULL`.
				n->parent->left = nullptr;	
			}else{
			//If `n` is the right child of its parent, set the parent's right pointer to `NULL`.
				n->parent->right = nullptr;
			}
			
			delete n;
			size--;
			return removedElem;
		}
		
		node* child = (n->left) ? n->left : n->right;
		if(n == n->parent->left){
			n->parent->left = child;
		} else{
			n->parent->right = child;
		}
		
		child->parent = n->parent;
		delete n;
		size--;
		
		return removedElem;
		
	}

    node* getRoot() override {
        return root;
    }

    int getSize() override {
        return size;
    }
};
