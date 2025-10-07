/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <string>

bool isValid(const std::string &expr) {
    std::stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } else {
            if (s.empty()) return false;
            char top = s.top();
            if (ch == ')' && top != '(') return false;
            if (ch == ']' && top != '[') return false;
            if (ch == '}' && top != '{') return false;
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();
    
    for (int i = 0; i < N; ++i) {
        std::string expr;
        std::getline(std::cin, expr);
        std::cout << (isValid(expr) ? "True" : "False") << std::endl;
    }
    return 0;
}
