/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> correct_order(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> correct_order[i];
    }

    std::vector<int> student_answer(n);
    int first_val;
    while (std::cin >> first_val) {
        student_answer[0] = first_val;
        for (int i = 1; i < n; ++i) {
            std::cin >> student_answer[i];
        }

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (correct_order[i - 1] == student_answer[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        std::cout << dp[n][n] << "\n";
    }

    return 0;
}
