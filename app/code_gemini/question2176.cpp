/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double preco_galao_dolar;
    double preco_litro_brasil_real;
    double cotacao_dolar;

    std::cin >> preco_galao_dolar;
    std::cin >> preco_litro_brasil_real;
    std::cin >> cotacao_dolar;

    double preco_litro_eua_real = (preco_galao_dolar * cotacao_dolar) / 3.8;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Gasolina EUA: R$ " << preco_litro_eua_real << std::endl;
    std::cout << "Gasolina Brasil: R$ " << preco_litro_brasil_real << std::endl;

    if (preco_litro_eua_real < preco_litro_brasil_real) {
        std::cout << "Mais barata nos EUA" << std::endl;
    } else if (preco_litro_eua_real > preco_litro_brasil_real) {
        std::cout << "Mais barata no Brasil" << std::endl;
    } else {
        std::cout << "Igual" << std::endl;
    }

    return 0;
}
