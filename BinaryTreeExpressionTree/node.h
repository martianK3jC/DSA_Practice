//node.h
#include <string>
using namespace std;

struct node {
	string elem;
	node* left;
	node* right;
	node* parent;

	// TODO evaluate method
	int evaluate() {
		if (isdigit(elem[0])){
            return stoi(elem);
        }
        
        int leftValue = left ? left->evaluate() : 0;
        int rightValue = right ? right->evaluate() : 0;
        
        switch (elem[0]) {
            case '+':
                return leftValue + rightValue;
            case '-':
                return leftValue - rightValue;
            case '*':
                return leftValue * rightValue;
            case '/':
                if (rightValue != 0) {
                    return leftValue / rightValue;
                } else {
                    throw logic_error("Division by zero error.");
                }
            default:
                throw logic_error("Invalid operator");
        }
	}

};