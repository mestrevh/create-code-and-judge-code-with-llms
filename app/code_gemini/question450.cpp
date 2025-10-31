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

    std::string type, description;
    std::cin >> type >> description;

    to_lower(type);
    to_lower(description);

    double price = 0.0;

    if (type == "terno") {
        if (description == "simples") {
            price = 120.40;
        } else if (description == "completo") {
            price = 150.35;
        } else if (description == "fraque") {
            price = 180.70;
        }
        price *= 0.93;
    } else if (type == "acessorio") {
        if (description == "gravata") {
            price = 30.00;
        } else if (description == "sapato") {
            price = 80.00;
        } else if (description == "cinto") {
            price = 15.00;
        }
    }

    std::cout << std::fixed << std::setprecision(2) << price << std::endl;

    return 0;
}
