/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::cout << "Digite a quantidade de ingredientes em cada produto (ovo, farinha, acucar e carne):" << std::endl;

    double quantidades[3][4];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> quantidades[i][j];
        }
    }

    std::cout << "Digite o preco de cada ingrediente (ovo, farinha, acucar e carne):" << std::endl;

    double precos[4];
    for (int i = 0; i < 4; ++i) {
        std::cin >> precos[i];
    }

    double custo_pastel = 0.0;
    double custo_empada = 0.0;
    double custo_kibe = 0.0;

    for (int i = 0; i < 4; ++i) {
        custo_pastel += quantidades[0][i] * precos[i];
        custo_empada += quantidades[1][i] * precos[i];
        custo_kibe += quantidades[2][i] * precos[i];
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "O custo do pastel e R$ " << custo_pastel << "." << std::endl;
    std::cout << "O custo da empada e R$ " << custo_empada << "." << std::endl;
    std::cout << "O custo do kibe e R$ " << custo_kibe << "." << std::endl;

    return 0;
}
