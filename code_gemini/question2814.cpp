/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int dias;
    int km_rodados;

    std::cout << "Digite a quantidade de dias de locacao:" << std::endl;
    std::cin >> dias;

    std::cout << "Digite a quantidade de km rodados:" << std::endl;
    std::cin >> km_rodados;

    if (dias < 0 || km_rodados < 0) {
        std::cout << "Valor invalido" << std::endl;
    } else {
        int custo_total = dias * 90;
        int km_incluidos = dias * 100;

        if (km_rodados > km_incluidos) {
            int km_extra = km_rodados - km_incluidos;
            custo_total += km_extra * 12;
        }

        std::cout << "Valor total a ser pago em reais: " << custo_total << std::endl;
    }

    return 0;
}
