/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <deque>
#include <string>

int main() {
    std::string operation;
    while (true) {
        std::stack<int> terminal0;
        std::deque<int> terminal1;
        int nextWagon = 0;

        while (std::cin >> operation) {
            if (operation == "FIM") {
                break;
            }
            if (operation[0] == 'E') {
                int wagonId = nextWagon++;
                if (operation == "E0") {
                    terminal0.push(wagonId);
                } else if (operation == "E1E") {
                    terminal1.push_front(wagonId);
                } else if (operation == "E1D") {
                    terminal1.push_back(wagonId);
                }
            } else if (operation[0] == 'S') {
                if (operation == "S0" && !terminal0.empty()) {
                    std::cout << terminal0.top() << std::endl;
                    terminal0.pop();
                } else if (operation == "S1E" && !terminal1.empty()) {
                    std::cout << terminal1.front() << std::endl;
                    terminal1.pop_front();
                } else if (operation == "S1D" && !terminal1.empty()) {
                    std::cout << terminal1.back() << std::endl;
                    terminal1.pop_back();
                }
            }
        }

        std::cout << terminal0.size() << std::endl;
        std::cout << terminal1.size() << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
