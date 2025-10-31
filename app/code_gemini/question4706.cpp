/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

void ordenar(std::vector<int>& numeros) {
    int n = numeros.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (numeros[j] < numeros[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = numeros[i];
            numeros[i] = numeros[min_idx];
            numeros[min_idx] = temp;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> lista(7);
    for (int i = 0; i < 7; ++i) {
        std::cin >> lista[i];
    }

    ordenar(lista);

    std::cout << "[";
    for (int i = 0; i < 7; ++i) {
        std::cout << lista[i];
        if (i < 6) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";

    return 0;
}
