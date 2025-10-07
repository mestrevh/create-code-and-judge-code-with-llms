/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int maiorPar(const std::vector<int>& lista) {
    int maior = -1;
    for (int num : lista) {
        if (num % 2 == 0 && num > maior) {
            maior = num;
        }
    }
    return maior;
}

int main() {
    std::vector<int> lista = {34, 30, 9, 35, 15, 6, -5, 32, -1, 0, 10, 18, 38, 15, 42};
    std::cout << maiorPar(lista) << std::endl;
    return 0;
}
