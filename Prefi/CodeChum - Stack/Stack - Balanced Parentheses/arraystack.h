#include<iostream>
#include<stack>
#include<string>
#include "arraystack.h"
using namespace std;

// TODO implement this method.
// Use the ArrayStack to perform the stack operations needed.
int is_balanced_parentheses(string str){
    //Stack* stack = new ArrayStack;
    stack<char> openBrackets;
    for(char c : str){
        if(c == '('||c=='{'||c=='['){
            openBrackets.push(c);
        } else if(c == ')' || c == '}' || c == ']'){
            if(openBrackets.empty()){
                return 3;
            }
            char top = openBrackets.top();
            if(c == ')' && top != '('||c == '}' && top != '{' || c == ']' && top != '['){
                return 1;
            }
            openBrackets.pop();
        }
    }
    
    if(!openBrackets.empty()){
        return 2;
    }
    return 0;
}

int main(){
    string str;
    cout << "Enter a string with parentheses: ";
    cin >> str;
    int res = is_balanced_parentheses(str);
    switch(res) {
        case 0:
            cout << "The parentheses are balanced!" << endl;
            break;
        case 1:
            cout << "The parentheses are not balanced due to mismatch!" << endl;
            break;
        case 2:
            cout << "The parentheses are not balanced due to missing closing parentheses!" << endl;
            break;
        case 3:
            cout << "The parentheses are not balanced due to missing opening parentheses!" << endl;
            break;
    }
    return 0;
}