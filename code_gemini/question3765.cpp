/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void OrdenaMatriz(int *maior, int *segundo, int *terceiro, int *menor, int *matriz) {
    matriz[0] = *menor;
    matriz[1] = *segundo;
    matriz[2] = *terceiro;
    matriz[3] = *maior;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> numeros;
    int valor;

    for (int i = 0; i < 25; ++i) {
        std::cin >> valor;
        if (valor != 0) {
            numeros.push_back(std::abs(valor));
        }
    }

    while (numeros.size() < 4) {
        numeros.push_back(0);
    }

    std::sort(numeros.begin(), numeros.end());

    int menor = numeros[0];
    int segundo_menor = numeros[1];
    int segundo_maior = numeros[2];
    int maior = numeros[3];

    int matriz_pequena[2][2];

    OrdenaMatriz(&maior, &segundo_maior, &segundo_menor, &menor, &matriz_pequena[0][0]);

    std::cout << matriz_pequena[0][0] << " " << matriz_pequena[0][1] << "\n";
    std::cout << matriz_pequena[1][0] << " " << matriz_pequena[1][1] << "\n";

    return 0;
}
