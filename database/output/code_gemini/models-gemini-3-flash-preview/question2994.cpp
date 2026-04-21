/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long R, N;
    if (!(std::cin >> R)) return 0;
    if (!(std::cin >> N)) return 0;

    long long soma = 0;
    for (long long i = 1; i <= N; i += R) {
        soma += i;
    }

    std::cout << "A somatoria da PA eh: " << soma << std::endl;

    return 0;
}