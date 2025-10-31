/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int quantidade_digitos(long long n) {
    if (n == 0) {
        return 1;
    }
    int contador = 0;
    while (n > 0) {
        n = n / 10;
        contador++;
    }
    return contador;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long numero;
    std::cin >> numero;
    std::cout << quantidade_digitos(numero) << std::endl;
    return 0;
}
