/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <limits>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> H[i];
    }

    int min_sum = std::numeric_limits<int>::max();
    int index = 0;
    int current_sum = 0;

    for (int i = 0; i < K; ++i) {
        current_sum += H[i];
    }
    min_sum = current_sum;

    for (int i = K; i < N; ++i) {
        current_sum += H[i] - H[i - K];
        if (current_sum < min_sum) {
            min_sum = current_sum;
            index = i - K + 1;
        }
    }

    std::cout << index + 1 << std::endl;
    return 0;
}
