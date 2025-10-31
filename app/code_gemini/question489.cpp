/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double totalClara = 0.0;
    double totalDiana = 0.0;

    for (int i = 0; i < 6; ++i) {
        double valor;
        std::string nome;
        std::cin >> valor >> nome;
        if (nome == "Clara") {
            totalClara += valor;
        } else {
            totalDiana += valor;
        }
    }

    std::cout << std::fixed << std::setprecision(2);

    if (totalClara > totalDiana) {
        double divida = (totalClara - totalDiana) / 2.0;
        std::cout << "DIANA\n" << divida << std::endl;
    } else if (totalDiana > totalClara) {
        double divida = (totalDiana - totalClara) / 2.0;
        std::cout << "CLARA\n" << divida << std::endl;
    } else {
        std::cout << "MORADORAS QUITES\n";
    }

    return 0;
}
