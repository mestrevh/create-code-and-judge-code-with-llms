/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> heights(N);

    for (int i = 0; i < N; i++) {
        std::cin >> heights[i];
    }

    int moves = 0;
    for (int i = 0; i < N - 1; i++) {
        int diff = heights[i] - M;
        if (diff != 0) {
            heights[i] -= diff;
            heights[i + 1] -= diff;
            moves += abs(diff);
        }
    }

    moves += abs(heights[N - 1] - M);
    std::cout << moves << std::endl;

    return 0;
}
