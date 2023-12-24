/*
ONP - Transform the Expression
#stack
Transform the algebraic expression with brackets into RPN form (Reverse Polish Notation). Two-argument operators: +, -, *, /, ^ (priority from the lowest to the highest), brackets ( ). Operands: only letters: a,b,...,z. Assume that there is only one RPN form (no expressions like a*b*c).

Input
t [the number of expressions <= 100]
expression [length <= 400]
[other expressions]
Text grouped in [ ] does not appear in the input file.

Output
The expressions in RPN form, one per line.
Example
Input:
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

Output:
abc*+
ab+zx+*
at+bac++cd+^*
*/

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

int getPrecedence(char op) {
    // Define operator precedence
    unordered_map<char, int> precedence;
    precedence['+'] = precedence['-'] = 1;
    precedence['*'] = precedence['/'] = 2;
    precedence['^'] = 3;
    return precedence[op];
}

string infixToPostfix(string &infix) {
    string postfix = "";
    stack<char> operatorStack;
    for (char c : infix) {
        if (c == '(') {
            // Left parenthesis, push onto the stack
            operatorStack.push(c);
        } else if (c == ')') {
            // Right parenthesis, pop and append operators until '(' is encountered
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Pop '('
        } 
        else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') 
        {
            // Operator, pop and append higher or equal precedence operators
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
        else
        {
        	postfix += c;
        }
    }

    // Pop any remaining operators from the stack
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // consume the newline character after reading t
    while (t--) {
        string expression;
        cin>>expression;
        cout << infixToPostfix(expression) << endl;
    }

    return 0;
}
