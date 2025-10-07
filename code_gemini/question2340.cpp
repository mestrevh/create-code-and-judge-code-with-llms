/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int funcao(int n) {
    if (n < 10) {
        return n;
    }
    return funcao(n / 10);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int digito_esquerda = funcao(n);
    if (digito_esquerda % 2 == 0) {
        std::cout << n + 2 << std::endl;
    } else {
        std::cout << n + 1 << std::endl;
    }
    return 0;
}
