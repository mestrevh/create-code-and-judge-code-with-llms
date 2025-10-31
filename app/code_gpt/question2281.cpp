/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int contarDigitos(unsigned long long n) {
    if (n == 0) return 0;
    return 1 + contarDigitos(n / 10);
}

int main() {
    unsigned long long n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << contarDigitos(n) << std::endl;
    }
    return 0;
}
