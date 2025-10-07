/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string text;
    std::getline(std::cin, text);

    char target_char;
    std::cin >> target_char;

    int target_count = 0;
    int letter_count = 0;
    char lower_target = tolower(target_char);

    for (char c : text) {
        if (isalpha(c)) {
            letter_count++;
            if (tolower(c) == lower_target) {
                target_count++;
            }
        }
    }

    std::cout << target_count << std::endl;

    if (letter_count > 0) {
        double percentage = (static_cast<double>(target_count) / letter_count) * 100.0;
        std::cout << std::fixed << std::setprecision(2) << percentage << "%" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(2) << 0.00 << "%" << std::endl;
    }

    return 0;
}
