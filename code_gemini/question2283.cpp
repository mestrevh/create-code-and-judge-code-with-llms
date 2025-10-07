/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long soma_digitos(long long n) {
    if (n == 0) {
        return 0;
    } else {
        return (n % 10) + soma_digitos(n / 10);
    }
}

int main() {
    long long n;
    std::cin >> n;
    std::cout << soma_digitos(n) << std::endl;
    return 0;
}
