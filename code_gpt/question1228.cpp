/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

double mediaImpares(const std::vector<int>& lista) {
    double soma = 0;
    int contador = 0;

    for (int num : lista) {
        if (num % 2 != 0) {
            soma += num;
            contador++;
        }
    }
    return (contador > 0) ? soma / contador : 0.0;
}

int main() {
    std::vector<int> lista = {20, 10, 4, 19, 18, 31, 22, 25, 24, 34, 2, 19, -1, -7, -2, 25, 24, 35, 29, 4};
    double resultado = mediaImpares(lista);
    std::cout << std::fixed << std::setprecision(2) << resultado << std::endl;
    return 0;
}
