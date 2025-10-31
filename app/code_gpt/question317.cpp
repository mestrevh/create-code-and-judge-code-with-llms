/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>

std::string processInput(const std::string &input) {
    std::stack<std::string> st;
    std::string current;
    bool home_pressed = false;

    for (char c : input) {
        if (c == '[') {
            st.push(current);
            current.clear();
            home_pressed = true;
        } else if (c == ']') {
            if (!st.empty()) {
                current = st.top() + current;
                st.pop();
            }
            home_pressed = false;
        } else {
            if (home_pressed) {
                current.insert(current.begin(), c);
            } else {
                current.push_back(c);
            }
        }
    }
    return current;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::cout << processInput(input) << std::endl;
    return 0;
}
