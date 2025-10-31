/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

std::vector<int> ordenar(std::vector<int> numeros) {
    for (size_t i = 0; i < numeros.size(); ++i) {
        for (size_t j = i + 1; j < numeros.size(); ++j) {
            if (numeros[i] > numeros[j]) {
                std::swap(numeros[i], numeros[j]);
            }
        }
    }
    return numeros;
}

int main() {
    std::vector<int> numeros(7);
    for (int i = 0; i < 7; ++i) {
        std::cin >> numeros[i];
    }
    std::vector<int> numerosOrdenados = ordenar(numeros);
    std::cout << "[";
    for (size_t i = 0; i < numerosOrdenados.size(); ++i) {
        std::cout << numerosOrdenados[i];
        if (i < numerosOrdenados.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    return 0;
}
