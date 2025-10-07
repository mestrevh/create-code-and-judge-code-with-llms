/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }

    long long max_sum = 0;
    int best_start = 0;
    int best_end = 0;

    long long current_sum = 0;
    int current_start = 0;

    for (int i = 0; i < n - 1; ++i) {
        if (values[i + 1] > values[i]) {
            if (current_sum == 0) {
                current_start = i + 1;
                current_sum = values[i] + values[i + 1];
            } else {
                current_sum += values[i + 1];
            }
        } else {
            if (current_sum > max_sum) {
                max_sum = current_sum;
                best_start = current_start;
                best_end = i + 1;
            }
            current_sum = 0;
        }
    }

    if (current_sum > max_sum) {
        max_sum = current_sum;
        best_start = current_start;
        best_end = n;
    }

    std::cout << best_start << " " << best_end << " " << max_sum << "\n";

    return 0;
}
