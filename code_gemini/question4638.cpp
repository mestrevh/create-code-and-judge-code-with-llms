/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::getline(std::cin, s);

    auto first = s.find_first_not_of(" \t\n\r\f\v");
    if (std::string::npos == first) {
        std::cout << "fracasso" << std::endl;
        return 0;
    }
    auto last = s.find_last_not_of(" \t\n\r\f\v");
    std::string password = s.substr(first, (last - first + 1));

    if (password.length() < 10) {
        std::cout << "fracasso" << std::endl;
        return 0;
    }

    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;

    for (char c : password) {
        if (!std::isalnum(static_cast<unsigned char>(c))) {
            std::cout << "fracasso" << std::endl;
            return 0;
        }
        if (std::isupper(static_cast<unsigned char>(c))) {
            has_upper = true;
        } else if (std::islower(static_cast<unsigned char>(c))) {
            has_lower = true;
        } else if (std::isdigit(static_cast<unsigned char>(c))) {
            has_digit = true;
        }
    }

    if (!has_upper || !has_lower || !has_digit) {
        std::cout << "fracasso" << std::endl;
        return 0;
    }

    if (password.length() >= 3) {
        std::string start_seq = password.substr(0, 3);
        std::string end_seq = password.substr(password.length() - 3);
        const std::vector<std::string> forbidden = {"123", "321", "000", "abc"};
        for (const auto& f : forbidden) {
            if (start_seq == f || end_seq == f) {
                std::cout << "fracasso" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "sucesso" << std::endl;

    return 0;
}
