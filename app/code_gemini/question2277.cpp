/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <climits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> p(n);
    bool has_allies = false;
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        if (p[i] > 0) {
            has_allies = true;
        }
    }

    if (!has_allies) {
        std::cout << "E uma armadilha\n";
        return 0;
    }

    long long max_global = -LLONG_MAX;
    long long current_sum = 0;
    int start_global = -1;
    int end_global = -1;
    int current_start = 0;

    for (int i = 0; i < n; ++i) {
        current_sum += p[i];

        if (current_sum >= max_global) {
            max_global = current_sum;
            start_global = current_start;
            end_global = i;
        }

        if (current_sum < 0) {
            current_sum = 0;
            current_start = i + 1;
        }
    }

    if (start_global == end_global) {
        std::cout << "Naruto deve libertar somente a posicao " << start_global + 1 << "\n";
    } else {
        std::cout << "Naruto deve libertar da posicao " << start_global + 1 << " ate a posicao " << end_global + 1 << "\n";
    }

    return 0;
}
