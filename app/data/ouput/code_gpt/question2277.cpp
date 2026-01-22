/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> power(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> power[i];
    }

    int total = 0;
    for (int p : power) {
        total += p;
    }

    if (total <= 0) {
        std::cout << "E uma armadilha" << std::endl;
        return 0;
    }

    int max_gain = 0;
    int current_gain = 0;
    int start = 0, best_start = 0, best_end = 0;

    for (int i = 0; i < N; ++i) {
        current_gain += power[i];

        if (current_gain < 0) {
            current_gain = 0;
            start = i + 1;
        }

        if (current_gain > max_gain) {
            max_gain = current_gain;
            best_start = start;
            best_end = i;
        }
    }

    if (best_start == best_end) {
        std::cout << "Naruto deve libertar somente a posicao " << best_start + 1 << std::endl;
    } else {
        std::cout << "Naruto deve libertar da posicao " << best_start + 1 << " ate a posicao " << best_end + 1 << std::endl;
    }

    return 0;
}
