/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n1, n2;
    std::cin >> n1 >> n2;
    int inicio = std::min(n1, n2);
    int fim = std::max(n1, n2);
    long long soma = 0;
    for (int i = inicio + 1; i < fim; ++i) {
        if (i % 4 == 0 && 1000 % i == 0) {
            soma += i;
        }
    }
    std::cout << soma << std::endl;
    return 0;
}
