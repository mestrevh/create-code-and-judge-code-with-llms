/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>
#include <deque>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string op;
    bool first_case = true;

    while (std::cin >> op) {
        if (!first_case) {
            std::cout << std::endl;
        }
        first_case = false;

        std::stack<int> terminal0;
        std::deque<int> terminal1;
        int next_wagon = 0;

        do {
            if (op == "FIM") {
                break;
            }

            if (op == "E0") {
                terminal0.push(next_wagon++);
            } else if (op == "S0") {
                if (!terminal0.empty()) {
                    std::cout << terminal0.top() << std::endl;
                    terminal0.pop();
                }
            } else if (op == "E1E") {
                terminal1.push_front(next_wagon++);
            } else if (op == "E1D") {
                terminal1.push_back(next_wagon++);
            } else if (op == "S1E") {
                if (!terminal1.empty()) {
                    std::cout << terminal1.front() << std::endl;
                    terminal1.pop_front();
                }
            } else if (op == "S1D") {
                if (!terminal1.empty()) {
                    std::cout << terminal1.back() << std::endl;
                    terminal1.pop_back();
                }
            }
        } while (std::cin >> op && op != "FIM");

        std::cout << terminal0.size() << std::endl;
        std::cout << terminal1.size() << std::endl;
    }

    return 0;
}
