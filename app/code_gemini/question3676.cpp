/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

double calculate_distance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double orcamento;
    std::cin >> orcamento;

    double x, y, a, b, c, d;
    std::cin >> x >> y >> a >> b >> c >> d;

    double gas1_preco, pedagio1;
    std::cin >> gas1_preco >> pedagio1;

    double gas2_preco, pedagio2;
    std::cin >> gas2_preco >> pedagio2;

    double dist1 = calculate_distance(x, y, a, b);
    double custo1 = (2.0 * dist1 / 12.0 * gas1_preco) + pedagio1;

    double dist2 = calculate_distance(x, y, c, d);
    double custo2 = (2.0 * dist2 / 12.0 * gas2_preco) + pedagio2;

    bool pode1 = (orcamento >= custo1);
    bool pode2 = (orcamento >= custo2);

    if (!pode1 && !pode2) {
        std::cout << "Ele vai ficar em casa" << std::endl;
        std::cout << -1 << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(2);
        if (pode1 && pode2) {
            if (custo1 < custo2) {
                std::cout << "Ele vai para o destino 1" << std::endl;
                std::cout << custo1 << std::endl;
            } else if (custo2 < custo1) {
                std::cout << "Ele vai para o destino 2" << std::endl;
                std::cout << custo2 << std::endl;
            } else {
                std::cout << "Tanto faz..." << std::endl;
                std::cout << custo1 << std::endl;
            }
        } else if (pode1) {
            std::cout << "Ele vai para o destino 1" << std::endl;
            std::cout << custo1 << std::endl;
        } else { 
            std::cout << "Ele vai para o destino 2" << std::endl;
            std::cout << custo2 << std::endl;
        }
    }

    return 0;
}
