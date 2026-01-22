/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x, y;
    char dummy_char;
    std::cin >> dummy_char >> x >> dummy_char >> y >> dummy_char;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string expression_line;
    std::getline(std::cin, expression_line);

    std::stringstream ss(expression_line);

    long long result = 0;
    int coefficient, power;
    char var_char;
    
    ss >> coefficient >> dummy_char >> var_char >> dummy_char >> power;
    if (var_char == 'x') {
        result += coefficient * static_cast<long long>(pow(x, power));
    } else {
        result += coefficient * static_cast<long long>(pow(y, power));
    }

    char op;
    while (ss >> op) {
        ss >> coefficient >> dummy_char >> var_char >> dummy_char >> power;
        long long term_value = 0;
        if (var_char == 'x') {
            term_value = coefficient * static_cast<long long>(pow(x, power));
        } else {
            term_value = coefficient * static_cast<long long>(pow(y, power));
        }

        if (op == '+') {
            result += term_value;
        } else {
            result -= term_value;
        }
    }

    if (result == 0) {
        std::cout << "a função não está definida em (" << x << "," << y << ") .-." << std::endl;
    } else {
        std::cout << "a função está definida em (" << x << "," << y << ")" << std::endl;
    }

    return 0;
}
