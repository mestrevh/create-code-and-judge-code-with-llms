/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> numbers;
    std::string line;
    while (std::cin >> line && line != "x") {
        numbers.push_back(std::stoi(line));
    }

    bool is_increasing = true;
    if (numbers.size() > 1) {
        for (size_t i = 1; i < numbers.size(); ++i) {
            if (numbers[i] < numbers[i - 1]) {
                is_increasing = false;
                break;
            }
        }
    }

    std::cout << std::boolalpha << is_increasing << '\n';

    if (is_increasing && !numbers.empty()) {
        double sum = 0.0;
        for (int num : numbers) {
            sum += num;
        }
        double average = sum / numbers.size();

        for (size_t i = 0; i < numbers.size(); ++i) {
            if (static_cast<double>(numbers[i]) >= average) {
                std::cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}
