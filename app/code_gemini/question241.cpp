/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, Q;
    int case_num = 1;
    while (std::cin >> N >> Q && (N != 0 || Q != 0)) {
        std::cout << "CASE# " << case_num++ << ":" << std::endl;
        std::vector<int> marbles(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> marbles[i];
        }
        std::sort(marbles.begin(), marbles.end());
        for (int i = 0; i < Q; ++i) {
            int query;
            std::cin >> query;
            auto it = std::lower_bound(marbles.begin(), marbles.end(), query);
            if (it != marbles.end() && *it == query) {
                int pos = std::distance(marbles.begin(), it) + 1;
                std::cout << query << " found at " << pos << std::endl;
            } else {
                std::cout << query << " not found" << std::endl;
            }
        }
    }
    return 0;
}
