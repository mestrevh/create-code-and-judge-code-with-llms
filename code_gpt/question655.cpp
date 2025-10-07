/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int N;
    while (std::cin >> N, N) {
        std::vector<int> samples(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> samples[i];
        }
        
        int peaks = 0;

        for (int i = 0; i < N; ++i) {
            int prev = samples[(i - 1 + N) % N];
            int curr = samples[i];
            int next = samples[(i + 1) % N];

            if ((curr > prev && curr > next) || (curr < prev && curr < next)) {
                ++peaks;
            }
        }

        std::cout << peaks << std::endl;
    }
    return 0;
}
