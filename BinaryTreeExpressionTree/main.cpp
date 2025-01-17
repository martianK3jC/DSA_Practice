//main.cpp
// 1. Go to the opInput method.
// 2. Go to node.h's evaluate method.
#include <iostream>
#include "mybinarytree.h"
using namespace std;

node* opInput(MyBinaryTree* tree, string prompt, node* parent);

int main(void) {
	MyBinaryTree* tree = new MyBinaryTree();
	char op;
	
	tree->root = opInput(tree, "root", NULL);
	
//	int input, ind;
//	node* nodes[100];
//	int res;
	
	
	do {
		cout << "Op: ";
		cin >> op;
		switch (op) {
			case 'p':
				tree->print();
			break;	
			case 'e':
				cout << "Answer: " << tree->evaluate() << endl;
			break;
			case 'x':
				cout << "Exiting" << endl;
			break;
			default:
				cout << "Invalid operation" << endl;
					}
		} while (op != 'x');
	return 0;
}

node* opInput(MyBinaryTree* tree, string prompt, node* parent) {
	string input;
	cout << "Enter " << prompt << ": ";
	cin >> input;
	
	node* n;
	
	switch (input[0]) {
	// TODO add cases for operations and default case for number
		case '+':
        case '*':
        case '/':
        case '-':
            n = tree->create_node(input, parent);
            n->left = opInput(tree, "left of " + input, n); 
            n->right = opInput(tree, "right of " + input, n);
            break;
        default:
            n = tree->create_node(input, parent);
    }                                            
    return n;
}

