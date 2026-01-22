/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long m;
    std::cin >> n >> m;

    std::vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> heights[i];
    }

    std::vector<int> unique_heights = heights;
    std::sort(unique_heights.begin(), unique_heights.end());
    unique_heights.erase(std::unique(unique_heights.begin(), unique_heights.end()), unique_heights.end());

    int low_idx = 0;
    int high_idx = unique_heights.size() - 1;
    int ans = 0;

    while (low_idx <= high_idx) {
        int mid_idx = low_idx + (high_idx - low_idx) / 2;
        int current_h = unique_heights[mid_idx];

        long long wood_collected = 0;
        for (int tree_height : heights) {
            if (tree_height > current_h) {
                wood_collected += tree_height - current_h;
            }
        }

        if (wood_collected >= m) {
            ans = current_h;
            low_idx = mid_idx + 1;
        } else {
            high_idx = mid_idx - 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
