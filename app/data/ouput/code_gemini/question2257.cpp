/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int verifica(unsigned int n, int x) {
    do {
        int digito = n % 10;
        if (x > 0 && digito == x - 1) {
            return 1;
        }
        if (x < 9 && digito == x + 1) {
            return 1;
        }
        n /= 10;
    } while (n > 0);
    return 0;
}

int main() {
    unsigned int n;
    int x;
    std::cin >> n >> x;
    if (verifica(n, x)) {
        std::cout << "sim" << std::endl;
    } else {
        std::cout << "nao" << std::endl;
    }
    return 0;
}
