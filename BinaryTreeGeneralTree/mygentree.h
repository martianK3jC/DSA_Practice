#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include "gentree.h"
using namespace std;


class MyGenTree : public GenTree {
	node* root;
	int size;

	public:
	MyGenTree() : root(nullptr), size(0){}
	
	node* addRoot(int e) {
		// TODO implementation [+10 pts]
		if (root){
		    throw logic_error ("Already has root");
		}
		root = new node();
		root->elem = e;
		root->parent = nullptr;
		root->children = new node* [10];
		root->num_child = 0;
		size++;
        return root;
	}

	node* addChild(node* p, int e) {
		// TODO implementation [+30 pts]
		if (!p) {
		    throw logic_error ("Parent is null");
		}
		
        if (p->num_child >= 10){
                throw logic_error ("Cannot add more children");
        }
        
        node* child = new node();
        child->elem = e;
        child->parent = p;
        child->children = new node*[10];
        child->num_child = 0;
        
        p->children[p->num_child] = child;
        p->num_child++;
        size++;
        return child;
	}

	void remove(node* n) {
		// TODO implementation [+35 pts]
		if (!n){
		    throw logic_error("Cannot remove a null node");
		}
		
		if (n->num_child > 0){
		    cout << n->elem << " has children" << endl;
		    return;
		}
		
		if (n->parent){
		    node* parent = n->parent;
		    for (int i = 0; i < parent->num_child; i++){
		         if (parent->children[i] == n){
		            for (int j = i; j < parent->num_child - 1; j++){
		                parent->children[j] = n->parent->children[j + 1];
		            }
		            parent->num_child--;
		            break;
		         }
		    }
		}

        delete[] n->children;
        delete n;
        size--;
	}
    
    int getSize() override{
        return size;
    }
    
    node* getRoot() override{
        return root;
    }
    
    // DO NOT MODIFY this line onwards.
	void print() {
		cout << "Size: " << size << endl;
		if (!root) {
			cout << "EMPTY" << endl;
			return;
		}
		node* curr = root;
		print_node("", root);
        cout << "Status: " << check_parent(root, NULL) << endl;
	}

	void print_node(string prefix, node* n) {
		cout << prefix;
        cout << "+-->: ";
        cout << n->elem << endl;
		for (int i = 0; i < n->num_child; i++) {
			print_node(prefix + "|   ", n->children[i]);
		}
	}

    bool check_parent(node* curr, node* par) {
        if (!curr) {
            return true;
        }
        if (curr->parent != par) {
            return false;
        }
        bool res = true;
		for (int i = 0; i < curr->num_child; i++) {
			res &= check_parent(curr->children[i], curr);
		}
        return res;
    }
};