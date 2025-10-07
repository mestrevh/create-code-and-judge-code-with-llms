/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int mergulho_count = 0;
    double total_revenue = 0.0;

    std::string passeio;

    while (std::cin >> passeio) {
        std::string passeio_lower = passeio;
        std::transform(passeio_lower.begin(), passeio_lower.end(), passeio_lower.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        double preco;

        if (passeio_lower == "mergulho") {
            mergulho_count++;
            preco = 50.0;
        } else if (passeio_lower == "barco") {
            preco = 65.0;
        } else if (passeio_lower == "buggy") {
            preco = 90.0;
        } else {
            break;
        }

        std::string residente;
        std::cin >> residente;

        if (!residente.empty() && std::tolower(static_cast<unsigned char>(residente[0])) == 's') {
            preco *= 0.60;
        }

        total_revenue += preco;
    }

    std::cout << mergulho_count << std::endl;
    std::cout << std::fixed << std::setprecision(2) << total_revenue << std::endl;

    return 0;
}
