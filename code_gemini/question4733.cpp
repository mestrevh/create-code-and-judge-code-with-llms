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

string convertToRPN(string expression) {
    string rpn = "";
    stack<char> operators;

    for (char c : expression) {
        if (isalpha(c)) {
            rpn += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                rpn += operators.top();
                operators.pop();
            }
            if (operators.empty() || operators.top() != '(') return "The expression is not valid";
            operators.pop();
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (!operators.empty() && operators.top() != '(' && precedence(c) <= precedence(operators.top())) {
                rpn += operators.top();
                operators.pop();
            }
            operators.push(c);
        } else {
            return "The expression is not valid";
        }
    }

    while (!operators.empty()) {
        if (operators.top() == '(' || operators.top() == ')') return "The expression is not valid";
        rpn += operators.top();
        operators.pop();
    }
    
    for (int i = 0; i < rpn.length(); i++){
        if (isalpha(rpn[i])){
            if (i + 1 < rpn.length() && isalpha(rpn[i+1])) return "The expression is not valid";
        }
    }

    return rpn;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); 

    while (t--) {
        string expression;
        getline(cin, expression);
        cout << convertToRPN(expression) << endl;
    }

    return 0;
}
