/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::string> valid_plates;
    std::vector<std::string> invalid_plates;

    for (int i = 0; i < n; ++i) {
        std::string plate;
        std::cin >> plate;

        int letter_count = 0;
        int digit_count = 0;

        for (char c : plate) {
            if (isdigit(c)) {
                digit_count++;
            } else if (isalpha(c)) {
                letter_count++;
            }
        }

        if (letter_count == 3 && digit_count == 4) {
            valid_plates.push_back(plate);
        } else {
            invalid_plates.push_back(plate);
        }
    }

    std::cout << valid_plates.size() << " placas:" << '\n';
    for (const std::string& plate : valid_plates) {
        std::cout << plate << '\n';
    }

    std::cout << invalid_plates.size() << " erros:" << '\n';
    for (const std::string& plate : invalid_plates) {
        std::cout << plate << '\n';
    }

    return 0;
}
