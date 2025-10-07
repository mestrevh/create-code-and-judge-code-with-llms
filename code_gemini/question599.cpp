/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> scores;
    scores.reserve(n);
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        scores.push_back(__builtin_popcount(num));
    }

    std::sort(scores.rbegin(), scores.rend());

    long long total_score = 0;
    for (int i = 0; i < k; ++i) {
        total_score += scores[i];
    }
    
    std::cout << total_score << '\n';
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
