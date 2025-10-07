/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string& str) {
    std::stack<char> s;
    for (char ch : str) {
        if (ch == '(' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == ']') {
            if (s.empty() || (ch == ')' && s.top() != '(') || (ch == ']' && s.top() != '[')) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    
    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line);
        line.erase(remove(line.begin(), line.end(), ' '), line.end());

        if (line.empty() || isBalanced(line)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
