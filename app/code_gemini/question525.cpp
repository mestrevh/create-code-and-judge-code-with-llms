/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int case_num = 1;
    while (std::cin >> n && n != 0) {
        std::cout << "Genome " << case_num++ << "\n";

        std::vector<int> genome(n);
        std::iota(genome.begin(), genome.end(), 1);

        int r;
        std::cin >> r;
        for (int k = 0; k < r; ++k) {
            int i, j;
            std::cin >> i >> j;
            std::reverse(genome.begin() + i - 1, genome.begin() + j);
        }

        int q;
        std::cin >> q;

        std::vector<int> position(n + 1);
        for (int k = 0; k < n; ++k) {
            position[genome[k]] = k + 1;
        }

        for (int k = 0; k < q; ++k) {
            int gene_val;
            std::cin >> gene_val;
            std::cout << position[gene_val] << "\n";
        }
    }

    return 0;
}
