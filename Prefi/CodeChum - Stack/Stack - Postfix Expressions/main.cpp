#include <iostream>
#include <string>
#include "arraystack.h"
using namespace std;

int main() {
	Stack* stack = new ArrayStack();
    string input;
    do {
    	cout << "Enter: ";
    	cin >> input;
    	int num;
    	int a, b, result;
    	switch (input[0]) {
    		// TODO add cases for operations here
    		case '+':
    		    b = stack->pop();
    		    a = stack->pop();
    		    result = a + b;
    		    stack ->push(result);
    		    break;
    		case '-':
    		    b = stack->pop();
    		    a = stack->pop();
    		    result = a - b;
    		    stack ->push(result);
    		    break;
    		case '*':
    		    b = stack->pop();
    		    a = stack->pop();
    		    result = a * b;
    		    stack ->push(result);
    		    break;
    		case '/':
    		    b = stack->pop();
    		    a = stack->pop();
    		    result = a / b;
    		    stack ->push(result);
    		    break;
    		case 'x':
    			cout << "Answer is " << stack->pop() << endl;
    			break;
    		default: // number
    			num = stoi(input); // converts string to int
                // TODO something
                stack->push(num);
    			break;
		}
	} while (input != "x");
	delete stack;
    return 0;
}