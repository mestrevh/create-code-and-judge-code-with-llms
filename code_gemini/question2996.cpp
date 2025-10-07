/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double preco_real;
    while (std::cin >> preco_real) {
        int preco_centavos = static_cast<int>(round(preco_real * 100));

        if (preco_centavos < 70 || preco_centavos > 620 || preco_centavos % 10 != 0) {
            std::cout << "Preco invalido, refaca a leitura do pacote.\n";
        } else {
            int selos50 = preco_centavos / 50;
            while (selos50 >= 0) {
                int restante = preco_centavos - (selos50 * 50);
                if (restante % 20 == 0) {
                    int selos20 = restante / 20;
                    std::cout << "Compre " << selos50 << " selo(s) de R$ 0.50 e " << selos20 << " selo(s) de R$ 0.20!\n";
                    return 0;
                }
                selos50--;
            }
        }
    }

    return 0;
}
