/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>

void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

long long calculate_cost(long long L, long long R, const std::vector<std::pair<long long, long long>>& teams) {
    long long total_cost = 0;
    for (const auto& team : teams) {
        long long l = team.first;
        long long r = team.second;
        if (l > L) {
            total_cost += l - L;
        }
        if (r < R) {
            total_cost += R - r;
        }
    }
    return total_cost;
}

int main() {
    fast_io();
    int n;
    std::cin >> n;

    int num_teams = 1;
    if (n > 0) {
        num_teams = 1 << n;
    }

    std::vector<std::pair<long long, long long>> teams(num_teams);
    std::vector<long long> ls(num_teams);
    std::vector<long long> rs(num_teams);

    for (int i = 0; i < num_teams; ++i) {
        std::cin >> teams[i].first >> teams[i].second;
        ls[i] = teams[i].first;
        rs[i] = teams[i].second;
    }

    size_t median_idx_l = (ls.size() - 1) / 2;
    std::nth_element(ls.begin(), ls.begin() + median_idx_l, ls.end());
    long long l_opt = ls[median_idx_l];

    size_t median_idx_r = (rs.size() - 1) / 2;
    std::nth_element(rs.begin(), rs.begin() + median_idx_r, rs.end());
    long long r_opt = rs[median_idx_r];

    if (l_opt <= r_opt) {
        std::cout << calculate_cost(l_opt, r_opt, teams) << std::endl;
    } else {
        std::vector<long long> all_vals;
        all_vals.reserve(num_teams * 2);
        for(const auto& team : teams) {
            all_vals.push_back(team.first);
            all_vals.push_back(team.second);
        }

        size_t median_idx_all = (all_vals.size() - 1) / 2;
        std::nth_element(all_vals.begin(), all_vals.begin() + median_idx_all, all_vals.end());
        long long x_opt = all_vals[median_idx_all];
        
        std::cout << calculate_cost(x_opt, x_opt, teams) << std::endl;
    }

    return 0;
}
