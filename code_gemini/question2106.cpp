/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long k;
    std::cin >> n >> k;

    std::vector<int> board(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> board[i];
    }

    const int LOG_K = 62;

    std::vector<std::vector<int>> jump(LOG_K, std::vector<int>(n));
    std::vector<std::vector<long long>> total_sum(LOG_K, std::vector<long long>(n));

    for (int i = 0; i < n; ++i) {
        jump[0][i] = (static_cast<long long>(i) + board[i]) % n;
        total_sum[0][i] = board[i];
    }

    for (int p = 1; p < LOG_K; ++p) {
        for (int i = 0; i < n; ++i) {
            int intermediate_node = jump[p - 1][i];
            jump[p][i] = jump[p - 1][intermediate_node];
            total_sum[p][i] = total_sum[p - 1][i] + total_sum[p - 1][intermediate_node];
        }
    }

    long long max_sum = -1;
    int best_start_pos = -1;

    for (int start_pos = 0; start_pos < n; ++start_pos) {
        long long current_sum = 0;
        int current_pos = start_pos;
        long long k_temp = k;
        
        for (int p = LOG_K - 1; p >= 0; --p) {
            if ((k_temp >> p) & 1LL) {
                current_sum += total_sum[p][current_pos];
                current_pos = jump[p][current_pos];
            }
        }
        
        if (current_sum > max_sum) {
            max_sum = current_sum;
            best_start_pos = start_pos;
        }
    }
    
    std::cout << best_start_pos << " " << max_sum << std::endl;

    return 0;
}
