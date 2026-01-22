/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    int N;
    int genome_case = 1;

    while (std::cout << "Digite o numero de genes do genoma entre 1 e 500:" << std::endl, std::cin >> N && N != 0) {
        std::vector<int> genome(N + 1);
        std::iota(genome.begin() + 1, genome.end(), 1);

        int R;
        std::cout << "Digite o numero de reversas entre 1 e 100:" << std::endl;
        std::cin >> R;

        for (int k = 0; k < R; ++k) {
            int i, j;
            std::cout << "Digite a posicao inicial da reversa:" << std::endl;
            std::cin >> i;
            std::cout << "Digite a posicao final da reversa:" << std::endl;
            std::cin >> j;
            std::reverse(genome.begin() + i, genome.begin() + j + 1);
        }

        int Q;
        std::cout << "Digite o número de consultas:" << std::endl;
        std::cin >> Q;

        std::cout << "Genome " << genome_case++ << std::endl;

        for (int k = 0; k < Q; ++k) {
            int pos;
            std::cout << "Digite a posicao a ser consultada entre 1 e " << N << ":" << std::endl;
            std::cin >> pos;
            std::cout << "Posicao " << pos << ": " << genome[pos] << std::endl;
        }
    }

    return 0;
}
