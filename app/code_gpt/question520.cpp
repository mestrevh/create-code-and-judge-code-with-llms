/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int T;
    std::cin >> T;
    for (int c = 1; c <= T; ++c) {
        int N, Q;
        std::cin >> N >> Q;
        std::vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> A[i];
        }
        std::cout << "caso " << c << ":\n";
        for (int i = 0; i < Q; ++i) {
            int X;
            std::cin >> X;
            int count = std::upper_bound(A.begin(), A.end(), X) - std::lower_bound(A.begin(), A.end(), X);
            std::cout << count << "\n";
        }
    }
    return 0;
}
