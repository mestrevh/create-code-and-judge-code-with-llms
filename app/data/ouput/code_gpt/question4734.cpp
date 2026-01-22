/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <unordered_map>

std::string infixToRPN(const std::string& expression) {
    std::stack<char> operators;
    std::string output;
    
    std::unordered_map<char, int> precedence = {
        {'+', 1}, {'-', 1},
        {'*', 2}, {'/', 2},
        {'^', 3}
    };

    for (char token : expression) {
        if (std::isalpha(token)) {
            output += token;
        } else if (token == '(') {
            operators.push(token);
        } else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                output += operators.top();
                operators.pop();
            }
            operators.pop();
        } else {
            while (!operators.empty() && precedence[operators.top()] >= precedence[token]) {
                output += operators.top();
                operators.pop();
            }
            operators.push(token);
        }
    }

    while (!operators.empty()) {
        output += operators.top();
        operators.pop();
    }

    return output;
}

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();

    while (t--) {
        std::string expression;
        std::getline(std::cin, expression);
        std::cout << infixToRPN(expression) << std::endl;
    }

    return 0;
}
