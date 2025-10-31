/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int i;
    std::cin >> i;

    if (i <= 0) {
        std::cout << "[]" << std::endl;
        return 0;
    }

    std::vector<int> numeros(i);
    for (int k = 0; k < i; ++k) {
        std::cin >> numeros[k];
    }

    int ultimo_numero = numeros.back();
    
    std::vector<int> resultado;
    for (const int& num : numeros) {
        if (num != ultimo_numero) {
            resultado.push_back(num);
        }
    }
    
    std::cout << "[";
    for (size_t k = 0; k < resultado.size(); ++k) {
        std::cout << resultado[k];
        if (k < resultado.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
