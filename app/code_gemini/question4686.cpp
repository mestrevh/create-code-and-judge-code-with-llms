/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::queue<int> q;
    long long sum = 0;
    std::string command;

    while (std::cin >> command && command != "exit") {
        if (command == "push") {
            int value;
            std::cin >> value;
            q.push(value);
            sum += value;
        } else if (command == "pop") {
            if (!q.empty()) {
                sum -= q.front();
                q.pop();
            }
        } else if (command == "sum") {
            std::cout << sum << "\n";
        } else if (command == "print") {
            std::queue<int> temp_q = q;
            bool first = true;
            while (!temp_q.empty()) {
                if (!first) {
                    std::cout << " ";
                }
                std::cout << temp_q.front();
                temp_q.pop();
                first = false;
            }
            std::cout << "\n";
        }
    }

    return 0;
}
