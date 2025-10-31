/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>
#include <cctype>

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 0;
    }
    if (op == '*' || op == '/') {
        return 1;
    }
    if (op == '^') {
        return 2;
    }
    return -1;
}

void solve() {
    std::string infix;
    std::cin >> infix;
    std::string postfix = "";
    std::stack<char> op_stack;

    for (char c : infix) {
        if (islower(c)) {
            postfix += c;
        } else if (c == '(') {
            op_stack.push(c);
        } else if (c == ')') {
            while (!op_stack.empty() && op_stack.top() != '(') {
                postfix += op_stack.top();
                op_stack.pop();
            }
            if (!op_stack.empty()) {
                op_stack.pop();
            }
        } else {
            while (!op_stack.empty() && op_stack.top() != '(' &&
                   (precedence(op_stack.top()) > precedence(c) ||
                    (precedence(op_stack.top()) == precedence(c) && c != '^'))) {
                postfix += op_stack.top();
                op_stack.pop();
            }
            op_stack.push(c);
        }
    }

    while (!op_stack.empty()) {
        postfix += op_stack.top();
        op_stack.pop();
    }

    std::cout << postfix << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}
