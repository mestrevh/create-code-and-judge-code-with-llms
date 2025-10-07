/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    double total_valor = 0.0;
    int total_kg = 0;

    for (int i = 1; i <= n; ++i) {
        double valor_dia;
        std::cin >> valor_dia;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string frutas_line;
        std::getline(std::cin, frutas_line);

        std::stringstream ss(frutas_line);
        std::string fruta;
        int kg_dia = 0;
        while (ss >> fruta) {
            kg_dia++;
        }

        std::cout << "dia " << i << ": " << kg_dia << " kg\n";

        total_valor += valor_dia;
        total_kg += kg_dia;
    }

    if (n > 0) {
        double media_kg = static_cast<double>(total_kg) / n;
        double media_valor = total_valor / n;

        std::cout << std::fixed << std::setprecision(2);
        std::cout << media_kg << " kg por dia\n";
        std::cout << "R$ " << media_valor << " por dia\n";
    }

    return 0;
}
