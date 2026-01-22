/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int test_case_count = 1;

    while (std::cin >> n && n != 0) {
        std::vector<int> diffs(n);
        for (int i = 0; i < n; ++i) {
            int x, y;
            std::cin >> x >> y;
            diffs[i] = x - y;
        }

        int max_sum = 0;
        int best_start = -1;
        int best_end = -1;

        int current_sum = 0;
        int current_start = 0;

        for (int i = 0; i < n; ++i) {
            current_sum += diffs[i];

            if (current_sum > max_sum) {
                max_sum = current_sum;
                best_start = current_start;
                best_end = i;
            } else if (current_sum == max_sum) {
                if (best_start != -1) {
                    if ((i - current_start) > (best_end - best_start)) {
                        best_start = current_start;
                        best_end = i;
                    }
                }
            }

            if (current_sum < 0) {
                current_sum = 0;
                current_start = i + 1;
            }
        }

        std::cout << "Teste " << test_case_count++ << "\n";
        if (max_sum > 0) {
            std::cout << best_start + 1 << " " << best_end + 1 << "\n";
        } else {
            std::cout << "nenhum\n";
        }
        std::cout << "\n";
    }

    return 0;
}
