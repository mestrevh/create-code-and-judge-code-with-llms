/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long soma = 0;
    long long num;
    while (std::cin >> num) {
        soma += num;
    }

    std::cout << soma << std::endl;

    return 0;
}