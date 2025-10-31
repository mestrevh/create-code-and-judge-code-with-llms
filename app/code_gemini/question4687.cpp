/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> data;
    std::string command;

    while (std::cin >> command) {
        if (command == "exit") {
            break;
        }

        if (command == "push") {
            int value;
            std::cin >> value;
            data.push_back(value);
        } else if (command == "pop") {
            if (!data.empty()) {
                data.pop_back();
            }
        } else if (command == "sum") {
            if (data.empty()) {
                std::cout << 0 << std::endl;
            } else {
                long long total_sum = 0;
                for (int x : data) {
                    total_sum += x;
                }
                std::cout << total_sum << std::endl;
            }
        } else if (command == "pow") {
            if (!data.empty()) {
                for (int x : data) {
                    std::cout << static_cast<long long>(x) * x << " ";
                }
            }
            std::cout << std::endl;
        } else if (command == "average") {
            if (data.empty()) {
                std::cout << "0.00" << std::endl;
            } else {
                long long total_sum = 0;
                for (int x : data) {
                    total_sum += x;
                }
                double avg = static_cast<double>(total_sum) / data.size();
                std::cout << std::fixed << std::setprecision(2) << avg << std::endl;
            }
        } else if (command == "print") {
            if (!data.empty()) {
                for (int x : data) {
                    std::cout << x << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
