/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int R, N;
    std::cin >> R >> N;

    long long soma = 0;
    for (int termo = 1; termo <= N; termo += R) {
        soma += termo;
    }

    std::cout << "A somatoria da PA eh: " << soma << '\n';

    return 0;
}
