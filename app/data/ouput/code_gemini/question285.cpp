/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n;
    std::cin >> n;
    if (n == 0) {
        std::cout << "NULO\n";
    } else {
        if (n > 0) {
            if (n % 2 == 0) {
                std::cout << "POSITIVO PAR\n";
            } else {
                std::cout << "POSITIVO IMPAR\n";
            }
        } else {
            if (n % 2 == 0) {
                std::cout << "NEGATIVO PAR\n";
            } else {
                std::cout << "NEGATIVO IMPAR\n";
            }
        }
    }
    return 0;
}
