/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::cin >> line;

    std::vector<int> numbers;
    std::string current_number_str;

    for (char c : line) {
        if (isdigit(c)) {
            current_number_str += c;
        } else {
            if (!current_number_str.empty()) {
                numbers.push_back(std::stoi(current_number_str));
                current_number_str.clear();
            }
        }
    }

    bool is_sorted = true;
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i - 1] > numbers[i]) {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) {
        std::cout << "Ordenado\n";
    } else {
        std::cout << "Nao ordenado\n";
    }

    return 0;
}
