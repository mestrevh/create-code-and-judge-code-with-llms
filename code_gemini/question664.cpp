/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>

int N;
std::vector<std::vector<double>> M;
std::vector<std::pair<int, int>> races;
std::vector<std::vector<double>> memo;

const std::vector<double>& get_probs(int k) {
    if (!memo[k].empty()) {
        return memo[k];
    }

    if (k <= N) {
        memo[k].assign(N + 1, 0.0);
        memo[k][k] = 1.0;
        return memo[k];
    }

    int A = races[k].first;
    int B = races[k].second;

    const std::vector<double>& dist_A = get_probs(A);
    const std::vector<double>& dist_B = get_probs(B);

    memo[k].assign(N + 1, 0.0);

    for (int i = 1; i <= N; ++i) {
        if (dist_A[i] == 0.0 && dist_B[i] == 0.0) {
            continue;
        }

        double prob_i_wins_vs_A_winner = 0.0;
        for (int j = 1; j <= N; ++j) {
            prob_i_wins_vs_A_winner += dist_A[j] * M[i][j];
        }

        double prob_i_wins_vs_B_winner = 0.0;
        for (int j = 1; j <= N; ++j) {
            prob_i_wins_vs_B_winner += dist_B[j] * M[i][j];
        }
        
        memo[k][i] = dist_A[i] * prob_i_wins_vs_B_winner + dist_B[i] * prob_i_wins_vs_A_winner;
    }

    return memo[k];
}

void solve() {
    M.assign(N + 1, std::vector<double>(N + 1, 0.0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            std::cin >> M[i][j];
        }
    }

    races.assign(2 * N, {0, 0});
    std::vector<bool> is_child(2 * N, false);
    for (int k = N + 1; k < 2 * N; ++k) {
        int A, B;
        std::cin >> A >> B;
        races[k] = {A, B};
        if (A > 0 && A < 2*N) is_child[A] = true;
        if (B > 0 && B < 2*N) is_child[B] = true;
    }
    
    int root = -1;
    for (int k = N + 1; k < 2 * N; ++k) {
        if (!is_child[k]) {
            root = k;
            break;
        }
    }
    
    memo.assign(2 * N, std::vector<double>());

    const std::vector<double>& final_dist = get_probs(root);
    std::cout << std::fixed << std::setprecision(6) << final_dist[1] << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    while (std::cin >> N && N != 0) {
        solve();
    }

    return 0;
}
