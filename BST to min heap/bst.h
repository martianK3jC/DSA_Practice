//bst.hpp
#include "mybinarytree.hpp"

class BST {
	BinaryTree* tree = new MyBinaryTree();

	public:
	// TODO convert bst to heap
	void convertToHeap() {

	}
	
	
	
	

	// WARNING! Do not modify the codes below!
	bool search(int num) {
		return search_node(tree->getRoot(), num);
	}

	bool search_node(node* n, int num) {
		if (n == NULL) {
			return false;
		}
		if (n->elem == num) {
			return true;
		}
		if (num > n->elem) {
			return search_node(n->right, num);
		} else {
			return search_node(n->left, num);
		}
	}

	bool insert(int num) {
		node* n = tree->getRoot();
		if (n == NULL) {
			tree->addRoot(num);
		}
		return insert_node(n, num);
	}

	bool insert_node(node* n, int num) {
		if (n == NULL) {
			return false;
		}
		if (n->elem == num) {
			return false;
		}
		if (num > n->elem) {
			if (!n->right) {
				tree->addRight(n, num);
				return true;
			} else {
				return insert_node(n->right, num);
			}
		} else {
			if (!n->left) {
				tree->addLeft(n, num);
				return true;
			} else {
				return insert_node(n->left, num);
			}
		}
	}

    // IGNORE for now
    bool remove(int num) {
        return false;
    }

	void print() {
		tree->print();
	}
};