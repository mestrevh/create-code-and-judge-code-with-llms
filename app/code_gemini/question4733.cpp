/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>
#include <cctype>

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void solve() {
    std::string expr;
    std::cin >> expr;

    std::stack<char> operators;
    std::string postfix;
    bool valid = true;
    
    // State machine for validation
    // 0: Expecting an operand or a left parenthesis. (Initial state, or after an operator)
    // 1: Expecting an operator or a right parenthesis. (After an operand or a right parenthesis)
    int state = 0;

    if (expr.empty()) {
        valid = false;
    }

    for (char c : expr) {
        if (!valid) break;

        if (islower(c)) { // Operand
            if (state != 0) { valid = false; break; }
            postfix += c;
            state = 1;
        } else if (isOperator(c)) { // Operator
            if (state != 1) { valid = false; break; }
            while (!operators.empty() && operators.top() != '(') {
                char topOp = operators.top();
                if (precedence(topOp) > precedence(c) || (precedence(topOp) == precedence(c) && c != '^')) {
                    postfix += topOp;
                    operators.pop();
                } else {
                    break;
                }
            }
            operators.push(c);
            state = 0;
        } else if (c == '(') { // Left Parenthesis
            if (state != 0) { valid = false; break; }
            operators.push(c);
            state = 0;
        } else if (c == ')') { // Right Parenthesis
            if (state != 1) { valid = false; break; }
            bool found_lparen = false;
            while (!operators.empty()) {
                char topOp = operators.top();
                operators.pop();
                if (topOp == '(') {
                    found_lparen = true;
                    break;
                }
                postfix += topOp;
            }
            if (!found_lparen) { valid = false; break; }
            state = 1;
        } else { // Invalid character
            valid = false;
            break;
        }
    }

    if (valid) {
        // A valid expression must end after an operand or a right parenthesis.
        if (state != 1) {
            valid = false;
        }
    }
    
    if (valid) {
        while (!operators.empty()) {
            char topOp = operators.top();
            if (topOp == '(') {
                valid = false; // Mismatched parenthesis
                break;
            }
            postfix += topOp;
            operators.pop();
        }
    }

    if (valid) {
        std::cout << postfix << std::endl;
    } else {
        std::cout << "The expression is not valid" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
