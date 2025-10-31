/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>

void to_lower(std::string& s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::tolower(c); });
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string comida, bebida;
    std::cin >> comida >> bebida;

    to_lower(comida);
    to_lower(bebida);

    double total = 0.0;

    if (comida == "lasanha") {
        total += 8.00;
    } else if (comida == "estrogonofe") {
        total += 11.00;
    }

    if (bebida == "refrigerante") {
        total += 3.00;
    } else if (bebida == "suco") {
        total += 2.50;
    }

    std::cout << std::fixed << std::setprecision(2) << total << std::endl;

    return 0;
}
