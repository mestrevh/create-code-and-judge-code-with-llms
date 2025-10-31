/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int somar_lista(const std::vector<int>& numeros) {
    int soma = 0;
    for (int num : numeros) {
        soma += num;
    }
    return soma;
}

int main() {
    std::vector<int> numeros;
    int n;
    while (std::cin >> n) {
        numeros.push_back(n);
    }
    int resultado = somar_lista(numeros);
    std::cout << resultado << std::endl;
    return 0;
}
