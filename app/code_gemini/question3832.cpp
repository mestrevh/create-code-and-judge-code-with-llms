/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    std::cin >> N >> M;

    int valor_a_pagar;
    if (M % 100 == 0) {
        valor_a_pagar = M;
    } else {
        valor_a_pagar = (M / 100 + 1) * 100;
    }

    if (N < valor_a_pagar) {
        std::cout << "Pedro vai ter que fugir\n";
    } else {
        int sobrou = N - valor_a_pagar;
        if (valor_a_pagar > M) {
            std::cout << "Pegou mais\n";
        }
        std::cout << "Esta pago\n";
        std::cout << "Sobrou " << sobrou << "\n";
    }

    return 0;
}
