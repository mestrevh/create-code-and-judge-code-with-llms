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

    std::stack<int> back_stack;
    std::stack<int> forward_stack;
    std::string command;
    bool active = false;

    while (std::cin >> command) {
        if (command == "ENTER") {
            if (active) {
                back_stack.push(1);
            }
            active = true;
            while (!forward_stack.empty()) {
                forward_stack.pop();
            }
        } else if (command == "BACK") {
            if (!back_stack.empty()) {
                forward_stack.push(1);
                back_stack.pop();
            }
        } else if (command == "FORWARD") {
            if (!forward_stack.empty()) {
                back_stack.push(1);
                forward_stack.pop();
            }
        }
    }

    std::cout << "BACK: " << back_stack.size() << "\n";
    std::cout << "FORWARD: " << forward_stack.size() << "\n";

    return 0;
}
