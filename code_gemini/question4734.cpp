/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToRPN(string infix) {
    string rpn;
    stack<char> operators;

    for (char c : infix) {
        if (isalnum(c)) {
            rpn += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                rpn += operators.top();
                operators.pop();
            }
            operators.pop(); 
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (!operators.empty() && operators.top() != '(' && precedence(c) <= precedence(operators.top())) {
                rpn += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        rpn += operators.top();
        operators.pop();
    }

    return rpn;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); 

    while (t--) {
        string infix;
        getline(cin, infix);
        cout << infixToRPN(infix) << endl;
    }

    return 0;
}
