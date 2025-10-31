/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <limits>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> times(N);

    for (int i = 0; i < N; ++i) {
        int sum = 0;
        for (int j = 0; j < M; ++j) {
            int time;
            std::cin >> time;
            sum += time;
        }
        times[i] = sum;
    }

    int winner = 0;
    for (int i = 1; i < N; ++i) {
        if (times[i] < times[winner]) {
            winner = i;
        }
    }

    std::cout << winner + 1 << std::endl;
    return 0;
}
