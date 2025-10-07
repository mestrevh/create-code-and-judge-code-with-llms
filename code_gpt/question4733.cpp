/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isValid(const string& exp) {
    int balance = 0;
    for (char c : exp) {
        if (c == '(') balance++;
        if (c == ')') balance--;
        if (balance < 0) return false;
        if (!isalnum(c) && c != '+' && c != '-' && c != '*' && c != '/' && c != '^' && c != '(' && c != ')') return false;
    }
    return balance == 0;
}

string infixToRPN(const string& exp) {
    stack<char> operators;
    string result;
    
    for (char c : exp) {
        if (isalnum(c)) {
            result += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                result += operators.top();
                operators.pop();
            }
            operators.pop();
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                result += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }
    
    while (!operators.empty()) {
        result += operators.top();
        operators.pop();
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string expression;
        getline(cin, expression);
        if (!isValid(expression)) {
            cout << "The expression is not valid\n";
        } else {
            cout << infixToRPN(expression) << "\n";
        }
    }
    return 0;
}
