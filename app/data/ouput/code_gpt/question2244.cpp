/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> ingressos(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> ingressos[i];
    }

    for (int i = 0; i < N; ++i) {
        if (ingressos[i] == i + 1) {
            std::cout << "o ingresso de numero " << ingressos[i] << " foi sorteado" << std::endl;
            break;
        }
    }

    return 0;
}
