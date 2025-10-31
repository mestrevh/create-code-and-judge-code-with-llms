/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::stack<std::vector<int>> st;
    std::string command;

    while (std::cin >> command) {
        if (command == "PUSH") {
            std::string line;
            // Consume the newline character left by std::cin >> command
            std::cin.ignore(); 
            std::getline(std::cin, line);

            std::stringstream ss(line);
            std::vector<int> numbers;
            int num;
            while (ss >> num) {
                numbers.push_back(num);
            }
            st.push(numbers);
        } else if (command == "POP") {
            if (st.empty()) {
                std::cout << "EMPTY STACK\n";
            } else {
                std::vector<int> top_list = st.top();
                st.pop();
                for (size_t i = 0; i < top_list.size(); ++i) {
                    std::cout << top_list[i] << (i == top_list.size() - 1 ? "" : " ");
                }
                std::cout << '\n';
            }
        }
    }

    return 0;
}
