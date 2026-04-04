/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (true) {
        std::cout << "Digite um numero (negativo para parar o programa):\n";
        if (!(std::cin >> n) || n < 0) {
            break;
        }
        std::cout << "Numero: " << n << "\n";
    }

    return 0;
}