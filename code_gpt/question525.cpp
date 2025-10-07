/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int test_case = 1;
    while (true) {
        int N;
        std::cin >> N;
        if (N == 0) break;

        std::vector<int> genome(N);
        std::iota(genome.begin(), genome.end(), 1);

        int R;
        std::cin >> R;
        for (int i = 0; i < R; ++i) {
            int a, b;
            std::cin >> a >> b;
            std::reverse(genome.begin() + (a - 1), genome.begin() + b);
        }

        int Q;
        std::cin >> Q;
        std::cout << "Genome " << test_case++ << "\n";
        for (int i = 0; i < Q; ++i) {
            int gene;
            std::cin >> gene;
            std::cout << genome[gene - 1] << "\n";
        }
    }

    return 0;
}
