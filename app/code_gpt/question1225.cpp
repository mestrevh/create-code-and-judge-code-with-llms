/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int maiorElemento(const std::vector<int>& lista) {
    return *std::max_element(lista.begin(), lista.end());
}

int main() {
    std::vector<int> lista = {9, 9, 4, 4, 3, 5, 8, 9, 7, 4, 1, 4, 10, 5, 3, 4, 3, 7, 7, 10};
    std::cout << maiorElemento(lista) << std::endl;
    return 0;
}
