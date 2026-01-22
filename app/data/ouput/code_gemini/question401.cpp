/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int SomaDigitos(int n) {
    int soma = 0;
    if (n < 0) {
        n = -n;
    }
    while (n > 0) {
        soma += n % 10;
        n /= 10;
    }
    return soma;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int numero;
    std::cin >> numero;
    std::cout << SomaDigitos(numero) << std::endl;
    return 0;
}
