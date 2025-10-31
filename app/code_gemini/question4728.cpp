/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);

    std::stack<char> word_stack;

    for (char c : line) {
        if (c == ' ') {
            while (!word_stack.empty()) {
                std::cout << word_stack.top();
                word_stack.pop();
            }
            std::cout << ' ';
        } else {
            word_stack.push(c);
        }
    }

    while (!word_stack.empty()) {
        std::cout << word_stack.top();
        word_stack.pop();
    }
    
    std::cout << std::endl;

    return 0;
}
