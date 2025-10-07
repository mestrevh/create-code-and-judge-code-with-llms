/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int B, N;
    while (std::cin >> B >> N && (B != 0 || N != 0)) {
        std::vector<int> reserves(B);
        for (int i = 0; i < B; ++i) {
            std::cin >> reserves[i];
        }
        for (int i = 0; i < N; ++i) {
            int D, C, V;
            std::cin >> D >> C >> V;
            reserves[D - 1] -= V;
            reserves[C - 1] += V;
        }
        bool possible = true;
        for (int i = 0; i < B; ++i) {
            if (reserves[i] < 0) {
                possible = false;
                break;
            }
        }
        if (possible) {
            std::cout << "S\n";
        } else {
            std::cout << "N\n";
        }
    }
    return 0;
}
