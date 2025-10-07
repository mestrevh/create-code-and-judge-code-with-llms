/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>

int roman_to_int(char r) {
    switch (r) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string roman;
    std::cin >> roman;

    if (roman.empty()) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int total = 0;
    total = roman_to_int(roman.back());

    for (int i = roman.length() - 2; i >= 0; --i) {
        if (roman_to_int(roman[i]) < roman_to_int(roman[i + 1])) {
            total -= roman_to_int(roman[i]);
        } else {
            total += roman_to_int(roman[i]);
        }
    }

    std::cout << total << std::endl;

    return 0;
}
