/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <climits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int matriz[3][3];
    double soma_positivos = 0.0;
    int count_positivos = 0;
    int menor_valor = INT_MAX;
    long long soma_nao_diagonal = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> matriz[i][j];

            if (matriz[i][j] < menor_valor) {
                menor_valor = matriz[i][j];
            }

            if (matriz[i][j] > 0) {
                soma_positivos += matriz[i][j];
                count_positivos++;
            }

            if (i != j) {
                soma_nao_diagonal += matriz[i][j];
            }
        }
    }

    double media = 0.0;
    if (count_positivos > 0) {
        media = soma_positivos / count_positivos;
    }

    int delta = 0;
    if (menor_valor % 2 == 0) {
        delta = 1;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << media << " " << menor_valor << " " << delta << " " << soma_nao_diagonal << std::endl;

    return 0;
}
