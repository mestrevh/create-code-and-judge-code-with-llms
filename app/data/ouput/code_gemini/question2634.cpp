/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int consumo;

    std::cout << "Digite o consumo de agua em m3:" << std::endl;
    std::cin >> consumo;

    if (consumo < 0) {
        std::cout << "Numeros negativos nao sao aceitos." << std::endl;
    } else {
        int valor = 7;

        if (consumo > 100) {
            valor += (20 * 1) + (70 * 2) + ((consumo - 100) * 5);
        } else if (consumo > 30) {
            valor += (20 * 1) + ((consumo - 30) * 2);
        } else if (consumo > 10) {
            valor += (consumo - 10) * 1;
        }

        std::cout << "O valor a ser pago e de R$ " << valor << "." << std::endl;
    }

    return 0;
}
