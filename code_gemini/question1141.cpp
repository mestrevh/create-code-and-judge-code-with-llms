/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

long long count_valid_squares(int N, const std::vector<std::vector<bool>>& forbidden) {
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N + 1, 0));
    long long count = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (!forbidden[i][j]) {
                dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                count += dp[i][j];
            }
        }
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, P;
    std::cin >> N >> P;

    std::vector<std::vector<bool>> has_black(N + 1, std::vector<bool>(N + 1, false));
    std::vector<std::vector<bool>> has_white(N + 1, std::vector<bool>(N + 1, false));
    std::vector<std::vector<bool>> has_stone(N + 1, std::vector<bool>(N + 1, false));

    for (int i = 0; i < P; ++i) {
        int r, c;
        std::cin >> r >> c;
        has_black[r][c] = true;
        has_stone[r][c] = true;
    }

    for (int i = 0; i < P; ++i) {
        int r, c;
        std::cin >> r >> c;
        has_white[r][c] = true;
        has_stone[r][c] = true;
    }

    long long total_no_white = count_valid_squares(N, has_white);
    long long total_no_black = count_valid_squares(N, has_black);
    long long total_empty = count_valid_squares(N, has_stone);

    long long black_score = total_no_white - total_empty;
    long long white_score = total_no_black - total_empty;

    std::cout << black_score << " " << white_score << std::endl;

    return 0;
}
