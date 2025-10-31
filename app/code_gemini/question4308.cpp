/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<std::string> correct_plates;
    std::vector<std::string> incorrect_plates;
    for (int i = 0; i < n; ++i) {
        std::string plate;
        std::cin >> plate;
        int letter_count = 0;
        int digit_count = 0;
        for (char c : plate) {
            if (std::isalpha(c)) {
                letter_count++;
            } else if (std::isdigit(c)) {
                digit_count++;
            }
        }
        if (letter_count == 3 && digit_count == 4) {
            correct_plates.push_back(plate);
        } else {
            incorrect_plates.push_back(plate);
        }
    }
    std::cout << correct_plates.size() << " placas:\n";
    for (const auto& plate : correct_plates) {
        std::cout << plate << "\n";
    }
    std::cout << incorrect_plates.size() << " erros:\n";
    for (const auto& plate : incorrect_plates) {
        std::cout << plate << "\n";
    }
    return 0;
}
