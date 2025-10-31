/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <string>

int main() {
    std::stack<std::string> back, forward;
    std::string action;
    std::string current;

    while (std::getline(std::cin, action)) {
        if (action == "ENTER") {
            if (!current.empty()) back.push(current);
            current = "OPENED"; // Simulating the current page
            while (!forward.empty()) forward.pop();
        } else if (action == "BACK") {
            if (!back.empty()) {
                forward.push(current);
                current = back.top();
                back.pop();
            }
        } else if (action == "FORWARD") {
            if (!forward.empty()) {
                back.push(current);
                current = forward.top();
                forward.pop();
            }
        }
    }

    std::cout << "BACK: " << back.size() << std::endl;
    std::cout << "FORWARD: " << forward.size() << std::endl;

    return 0;
}
