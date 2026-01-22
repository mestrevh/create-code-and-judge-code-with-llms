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

    int d;
    std::string p;
    int m;

    std::cin >> d >> p >> m;

    std::string quotient;
    int remainder = 0;
    bool leading_zero = true;

    for (char digit_char : p) {
        int current_number = remainder * 10 + (digit_char - '0');
        int quotient_digit = current_number / m;
        remainder = current_number % m;

        if (quotient_digit > 0 || !leading_zero) {
            quotient += std::to_string(quotient_digit);
            leading_zero = false;
        }
    }

    if (quotient.empty()) {
        quotient = "0";
    }

    std::cout << quotient << " " << remainder << std::endl;

    return 0;
}
