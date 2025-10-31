/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char d;
    std::string n;

    while (std::cin >> d >> n) {
        if (d == '0' && n == "0") {
            break;
        }

        std::string result;
        for (char c : n) {
            if (c != d) {
                result += c;
            }
        }

        if (result.empty()) {
            std::cout << "0\n";
            continue;
        }

        size_t first_digit_pos = result.find_first_not_of('0');

        if (std::string::npos == first_digit_pos) {
            std::cout << "0\n";
        } else {
            std::cout << result.substr(first_digit_pos) << "\n";
        }
    }

    return 0;
}
