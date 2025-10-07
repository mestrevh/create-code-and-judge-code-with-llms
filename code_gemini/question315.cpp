/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string input_str;
    std::cin >> input_str;

    std::string sanitized_str;
    sanitized_str.reserve(input_str.length());
    for (char c : input_str) {
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F')) {
            sanitized_str += c;
        } else {
            sanitized_str += '0';
        }
    }

    if (sanitized_str.empty()) {
        std::cout << "(0,0,0)\n";
        return 0;
    }

    size_t len = sanitized_str.length();
    size_t new_len = (len + 2) / 3 * 3;
    if (new_len == 0 && len > 0) {
        new_len = 3;
    }
    sanitized_str.resize(new_len, '0');

    size_t group_size = new_len / 3;

    std::string hex_r = sanitized_str.substr(0, 2);
    std::string hex_g = sanitized_str.substr(group_size, 2);
    std::string hex_b = sanitized_str.substr(group_size * 2, 2);

    unsigned long r = std::stoul(hex_r, nullptr, 16);
    unsigned long g = std::stoul(hex_g, nullptr, 16);
    unsigned long b = std::stoul(hex_b, nullptr, 16);

    std::cout << "(" << r << "," << g << "," << b << ")\n";

    return 0;
}
