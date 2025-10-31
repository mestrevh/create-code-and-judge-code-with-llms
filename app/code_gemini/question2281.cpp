/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int contaDigitos(unsigned int n) {
    if (n < 10) {
        return 1;
    }
    return 1 + contaDigitos(n / 10);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    unsigned int n;
    std::cin >> n;
    std::cout << contaDigitos(n) << std::endl;
    return 0;
}
