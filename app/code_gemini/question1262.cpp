/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<double> notas(n);
    std::vector<double> pesos(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> notas[i];
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> pesos[i];
    }

    double soma_produtos = 0.0;
    double soma_pesos = 0.0;

    for (int i = 0; i < n; ++i) {
        soma_produtos += notas[i] * pesos[i];
        soma_pesos += pesos[i];
    }

    double media_ponderada = 0.0;
    if (soma_pesos != 0) {
        media_ponderada = soma_produtos / soma_pesos;
    }

    std::cout << std::fixed << std::setprecision(2) << media_ponderada << std::endl;

    return 0;
}
