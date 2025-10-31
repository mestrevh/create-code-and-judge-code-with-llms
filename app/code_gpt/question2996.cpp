/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double valor;
    while (std::cin >> valor) {
        int centavos = static_cast<int>(valor * 100);
        if (centavos < 70 || centavos > 620 || centavos % 10 != 0) {
            std::cout << "Preco invalido, refaca a leitura do pacote." << std::endl;
            continue;
        }
        int selos50 = centavos / 50;
        centavos %= 50;
        int selos20 = centavos / 20;
        std::cout << "Compre " << selos50 << " selo(s) de R$ 0.50 e " << selos20 << " selo(s) de R$ 0.20!" << std::endl;
    }
    return 0;
}
