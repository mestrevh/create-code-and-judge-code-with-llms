/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

void generate_A(int index, int end_index, int count, long long cost, const std::vector<int>& P, long long Q, std::vector<std::pair<long long, int>>& results) {
    if (index == end_index) {
        results.push_back({cost, count});
        return;
    }
    generate_A(index + 1, end_index, count, cost, P, Q, results);
    if (cost + P[index] <= Q) {
        generate_A(index + 1, end_index, count + 1, cost + P[index], P, Q, results);
    }
}

void generate_B(int index, int end_index, int count, long long cost, const std::vector<int>& P, long long Q, std::vector<std::vector<long long>>& results) {
    if (index == end_index) {
        results[count].push_back(cost);
        return;
    }
    generate_B(index + 1, end_index, count, cost, P, Q, results);
    if (cost + P[index] <= Q) {
        generate_B(index + 1, end_index, count + 1, cost + P[index], P, Q, results);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int K;
    std::cin >> K;
    for (int c = 0; c < K; ++c) {
        int L, M;
        long long Q;
        std::cin >> L;
        std::vector<int> P(L);
        for (int i = 0; i < L; ++i) {
            std::cin >> P[i];
        }
        std::cin >> M >> Q;
        int mid = L / 2;
        std::vector<std::pair<long long, int>> groupA_results;
        generate_A(0, mid, 0, 0, P, Q, groupA_results);
        int sizeB = L - mid;
        std::vector<std::vector<long long>> groupB_costs_by_count(sizeB + 1);
        generate_B(mid, L, 0, 0, P, Q, groupB_costs_by_count);
        for (int i = 0; i <= sizeB; ++i) {
            std::sort(groupB_costs_by_count[i].begin(), groupB_costs_by_count[i].end());
        }
        long long total_ways = 0;
        for (const auto& pair_a : groupA_results) {
            long long cost_a = pair_a.first;
            int count_a = pair_a.second;
            int min_count_b = M - count_a;
            if (min_count_b < 0) {
                min_count_b = 0;
            }
            for (int count_b = min_count_b; count_b <= sizeB; ++count_b) {
                if (groupB_costs_by_count[count_b].empty()) {
                    continue;
                }
                long long max_cost_b = Q - cost_a;
                auto it = std::upper_bound(groupB_costs_by_count[count_b].begin(), groupB_costs_by_count[count_b].end(), max_cost_b);
                total_ways += (it - groupB_costs_by_count[count_b].begin());
            }
        }
        std::cout << "caso " << c << ": " << total_ways << std::endl;
    }
    return 0;
}
