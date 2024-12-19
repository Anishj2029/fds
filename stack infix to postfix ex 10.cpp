// Implement C++ program for expression conversion as infix to postfix and its evaluation 
// using stack based on given conditions: 
// 1. Operands and operator, both must be single character.
// 2. Input Postfix expression must be in a desired format.
// 3. Only '+', '-', '*' and '/ ' operators are expected.
#include<iostream>
#include<stack>
using namespace std;

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

int applyOrder(int a, int b, char c) {
    switch(c) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

bool isOperand(char c) {
    return (c >= '0' && c <= '9');
}

string infixToPostfix(string infix) {
    stack<char> obj;
    string postfix = "";
    
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        if (isOperand(c)) {
            postfix += c;  
        }
        else if (c == '(') {
            obj.push(c);  
        }
        else if (c == ')') {
            while (!obj.empty() && obj.top() != '(') {
                postfix += obj.top();  
                obj.pop();
            }
            obj.pop();  
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!obj.empty() && precedence(obj.top()) >= precedence(c)) {
                postfix += obj.top();
                obj.pop();
            }
            obj.push(c);  
        }
    }
    while (!obj.empty()) {
        postfix += obj.top();
        obj.pop();
    }
    
    return postfix;
}

int evaluatePostfix(string postfix) {
    stack<int> obj1;
    
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        
        if (isOperand(c)) {
            obj1.push(c - '0'); 
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = obj1.top();
            obj1.pop();
            int a = obj1.top();
            obj1.pop();
            int result = applyOrder(a, b, c);
            obj1.push(result); 
        }
    }
    
    return obj1.top(); 
}

int main() {
    string infix;
    cout << "Enter the infix expression (e.g., 3*(2+1)): ";
    cin >> infix;
    
    string postfix = infixToPostfix(infix);
    cout << "The postfix expression is: " << postfix << endl;
    
    int result = evaluatePostfix(postfix);
    cout << "The result of the postfix evaluation is: " << result << endl;
    
    return 0;
}
