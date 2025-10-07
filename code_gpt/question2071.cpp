/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    while (std::cin >> N, N) {
        std::vector<int> cartas(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> cartas[i];
        }
        int max_forca = *std::max_element(cartas.begin(), cartas.end());
        int count_max = std::count(cartas.begin(), cartas.end(), max_forca);
        std::cout << max_forca << " " << count_max << std::endl;
    }
    return 0;
}
