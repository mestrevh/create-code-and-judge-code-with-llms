/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    long long soma = 0;
    int elemento;
    for (int i = 0; i < n; ++i) {
        std::cin >> elemento;
        soma += elemento;
    }
    std::cout << soma << '\n';
    return 0;
}
