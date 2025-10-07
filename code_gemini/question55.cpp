/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> numeros(10);
    for (int i = 0; i < 10; ++i) {
        std::cin >> numeros[i];
    }

    int ultimo_numero = numeros.back();
    int contador = 0;

    for (int numero : numeros) {
        if (numero == ultimo_numero) {
            contador++;
        }
    }

    std::cout << "O numero " << ultimo_numero << " apareceu " << contador << " vezes." << std::endl;

    return 0;
}
