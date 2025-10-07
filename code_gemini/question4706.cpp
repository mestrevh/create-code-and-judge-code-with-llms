/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

std::vector<int> ordenar(std::vector<int> lista) {
    for (int i = 0; i < 7; ++i) {
        for (int j = i + 1; j < 7; ++j) {
            if (lista[i] > lista[j]) {
                int temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
    return lista;
}

int main() {
    std::vector<int> numeros(7);
    for (int i = 0; i < 7; ++i) {
        std::cin >> numeros[i];
    }
    std::vector<int> resultado = ordenar(numeros);
    std::cout << "[";
    for (int i = 0; i < 7; ++i) {
        std::cout << resultado[i];
        if (i < 6) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
    return 0;
}

