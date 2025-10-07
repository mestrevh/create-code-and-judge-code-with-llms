/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

void print_stack(const std::vector<int>& s) {
    if (!s.empty()) {
        auto it = s.rbegin();
        std::cout << *it;
        ++it;
        for (; it != s.rend(); ++it) {
            std::cout << " " << *it;
        }
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> stack;
    std::string command;

    while (std::cin >> command && command != "Fim") {
        if (command == "Empilhar") {
            int value;
            std::cin >> value;
            stack.push_back(value);
            print_stack(stack);
        } else if (command == "Desempilhar") {
            if (!stack.empty()) {
                stack.pop_back();
            }
            print_stack(stack);
        }
    }

    return 0;
}
