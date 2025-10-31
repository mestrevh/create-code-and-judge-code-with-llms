/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <map>

void solve_odd_m(long long N, int M) {
    int limit = 2 * M + 205;
    if (N < limit) {
        limit = N;
    }

    std::vector<std::vector<bool>> is_losing_state(limit + 1, std::vector<bool>(M + 1, false));

    for (int j = 1; j <= M; ++j) {
        is_losing_state[0][j] = true;
    }

    std::map<std::vector<bool>, int> history;

    for (int i = 1; i <= limit; ++i) {
        std::vector<int> good_moves;
        for (int k = 1; k <= M; ++k) {
            if (i - k >= 0) {
                if (is_losing_state[i - k][k]) {
                    good_moves.push_back(k);
                }
            }
        }

        if (good_moves.empty()) {
            for (int j = 1; j <= M; ++j) is_losing_state[i][j] = true;
        } else if (good_moves.size() == 1) {
            is_losing_state[i][good_moves[0]] = true;
        }
        
        if (i >= M) {
            std::vector<bool> current_state_key;
            for(int k = 0; k < M; ++k) {
                for(int j=1; j<=M; ++j){
                    current_state_key.push_back(is_losing_state[i-k][j]);
                }
            }

            if (history.count(current_state_key)) {
                int start_cycle = history[current_state_key];
                int len_cycle = i - start_cycle;
                
                long long final_idx = start_cycle + (N - start_cycle) % len_cycle;

                std::vector<int> final_good_moves;
                for (int k = 1; k <= M; ++k) {
                    if (final_idx - k >= 0) {
                        if (is_losing_state[final_idx - k][k]) {
                            final_good_moves.push_back(k);
                        }
                    }
                }

                if (final_good_moves.empty()) {
                     std::cout << "Carlos" << std::endl;
                } else {
                     std::cout << "Paula" << std::endl;
                }
                return;
            }
            history[current_state_key] = i;
        }
    }

    std::vector<int> final_good_moves;
    for (int k = 1; k <= M; ++k) {
        if (N - k >= 0) {
            if (is_losing_state[N - k][k]) {
                final_good_moves.push_back(k);
            }
        }
    }
    
    if (final_good_moves.empty()) {
        std::cout << "Carlos" << std::endl;
    } else {
        std::cout << "Paula" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long N;
    int M;
    std::cin >> N >> M;

    if (N <= M) {
        std::cout << "Paula" << std::endl;
        return 0;
    }

    if (M % 2 == 0) {
        if (N % (M + 1) == 0) {
            std::cout << "Carlos" << std::endl;
        } else {
            std::cout << "Paula" << std::endl;
        }
        return 0;
    }

    solve_odd_m(N, M);

    return 0;
}
