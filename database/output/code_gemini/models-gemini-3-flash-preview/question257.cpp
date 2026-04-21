/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    if (std::getline(std::cin, s)) {
        int digit_count = 0;
        for (char c : s) {
            if (std::isdigit(static_cast<unsigned char>(c))) {
                digit_count++;
            }
        }
        std::cout << digit_count << std::endl;
    }

    return 0;
}