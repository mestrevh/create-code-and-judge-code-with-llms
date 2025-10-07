/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;

    for (int t = 1; t <= T; ++t) {
        std::cout << "caso " << t << ":\n";
        int N, Q;
        std::cin >> N >> Q;

        std::vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> A[i];
        }

        for (int i = 0; i < Q; ++i) {
            int X;
            std::cin >> X;
            auto lower = std::lower_bound(A.begin(), A.end(), X);
            auto upper = std::upper_bound(A.begin(), A.end(), X);
            std::cout << std::distance(lower, upper) << '\n';
        }
    }

    return 0;
}
