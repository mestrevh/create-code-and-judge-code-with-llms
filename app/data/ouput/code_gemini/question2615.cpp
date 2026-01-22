/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int divida;
    int pagamento_max;

    std::cin >> divida;
    std::cin >> pagamento_max;

    while (divida > 0) {
        std::cout << "(antes) " << divida << "\n";

        if (divida >= pagamento_max) {
            divida -= pagamento_max;
        } else {
            divida = 0;
        }

        std::cout << "(depois) " << divida << "\n";
    }

    return 0;
}
