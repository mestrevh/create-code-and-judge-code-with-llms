/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

void solve() {
    long long n, r_val;
    std::cin >> n >> r_val;

    std::vector<long long> shot_rows_1based;
    std::vector<long long> shot_cols_1based;

    for (int i = 0; i < r_val; ++i) {
        int type;
        long long pos;
        std::cin >> type >> pos;
        if (type == 0) {
            shot_rows_1based.push_back(pos);
        } else {
            shot_cols_1based.push_back(pos);
        }
    }

    std::sort(shot_rows_1based.begin(), shot_rows_1based.end());
    shot_rows_1based.erase(std::unique(shot_rows_1based.begin(), shot_rows_1based.end()), shot_rows_1based.end());

    std::sort(shot_cols_1based.begin(), shot_cols_1based.end());
    shot_cols_1based.erase(std::unique(shot_cols_1based.begin(), shot_cols_1based.end()), shot_cols_1based.end());

    long long total_pins = 2LL * n * n + 2LL * n + 1;

    long long removed_by_rows = 0;
    for (long long row_1b : shot_rows_1based) {
        long long row_0b = row_1b - 1;
        long long dist = std::abs(row_0b - n);
        removed_by_rows += 2LL * (n - dist) + 1;
    }

    long long removed_by_cols = 0;
    std::vector<long long> unique_cols_0based;
    unique_cols_0based.reserve(shot_cols_1based.size());
    for (long long col_1b : shot_cols_1based) {
        long long col_0b = col_1b - 1;
        unique_cols_0based.push_back(col_0b);
        long long dist = std::abs(col_0b - n);
        removed_by_cols += 2LL * (n - dist) + 1;
    }

    long long intersections = 0;
    if (!shot_rows_1based.empty() && !shot_cols_1based.empty()) {
        for (long long row_1b : shot_rows_1based) {
            long long row_0b = row_1b - 1;
            long long dist_r = std::abs(row_0b - n);
            long long c_min = dist_r;
            long long c_max = 2LL * n - dist_r;

            auto it_low = std::lower_bound(unique_cols_0based.begin(), unique_cols_0based.end(), c_min);
            auto it_high = std::upper_bound(unique_cols_0based.begin(), unique_cols_0based.end(), c_max);
            
            intersections += std::distance(it_low, it_high);
        }
    }
    
    long long total_removed = removed_by_rows + removed_by_cols - intersections;
    long long remaining = total_pins - total_removed;

    std::cout << remaining << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
