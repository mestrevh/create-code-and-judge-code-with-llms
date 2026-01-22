/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> matrix[i][j];
            }
        }

        int max_sum = INT_MIN;

        for (int left = 0; left < n; ++left) {
            std::vector<int> temp(n, 0);
            for (int right = left; right < n; ++right) {
                for (int i = 0; i < n; ++i) {
                    temp[i] += matrix[i][right];
                }

                int current_max = temp[0];
                int max_so_far = temp[0];

                for (int i = 1; i < n; ++i) {
                    current_max = std::max(temp[i], current_max + temp[i]);
                    max_so_far = std::max(max_so_far, current_max);
                }
                
                max_sum = std::max(max_sum, max_so_far);
            }
        }

        std::cout << max_sum << "\n";
    }

    return 0;
}
