/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

void solve(int case_num) {
    int l, i;
    std::cin >> l >> i;

    std::cout << "Caso " << case_num << ":\n";

    int H = 2 * l;
    int W = 2 * l + 1;

    std::vector<std::string> grid(H, std::string(W, ' '));

    for (int r : {0, H - 1}) {
        grid[r][0] = '*';
        grid[r][1] = '*';
        grid[r][W - 2] = '*';
        grid[r][W - 1] = '*';
        for (int k = 1; k <= l - 1; ++k) {
            if (1 + 2 * k < W - 1) {
                grid[r][1 + 2 * k] = '*';
            }
        }
    }

    for (int r = 1; r < H - 1; ++r) {
        grid[r][0] = '*';
        grid[r][W - 1] = '*';
    }

    for (int r = 1; r < l; ++r) {
        grid[r][r + 1] = '*';
        grid[r][W - 1 - (r + 1)] = '*';
    }
    for (int r = l; r < H - 1; ++r) {
        int mirrored_r = H - 1 - r;
        grid[r][mirrored_r + 1] = '*';
        grid[r][W - 1 - (mirrored_r + 1)] = '*';
    }

    long long v_total = (l - 2LL) * (l - 2LL);
    long long v_lower = 0;
    if (i > 0) {
        v_lower = (long long)i * (2LL * l - (long long)i - 4LL);
    }
    long long v_rem = v_total - v_lower;

    for (int k_lower = 1; k_lower <= i; ++k_lower) {
        int r = H - 2 - (k_lower - 1);
        int mirrored_r = k_lower;
        int left_star = mirrored_r + 1;
        int right_star = W - 1 - (mirrored_r + 1);
        for (int c = left_star + 1; c < right_star; ++c) {
            grid[r][c] = '.';
        }
    }

    for (int k_upper = 1; k_upper <= l - 2; ++k_upper) {
        if (v_rem <= 0) break;
        
        long long width = 2LL * k_upper - 1;
        long long sand_to_place = std::min(v_rem, width);
        
        int r = (l - 1) - k_upper;
        int center_col = l;
        int start_c = center_col - (sand_to_place - 1) / 2;
        int end_c = center_col + (sand_to_place - 1) / 2;
        
        for (int c = start_c; c <= end_c; ++c) {
            grid[r][c] = '.';
        }
        v_rem -= sand_to_place;
    }

    for (int r = 0; r < H; ++r) {
        std::cout << grid[r] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    std::cin >> N;
    for (int i = 1; i <= N; ++i) {
        solve(i);
    }
    return 0;
}
