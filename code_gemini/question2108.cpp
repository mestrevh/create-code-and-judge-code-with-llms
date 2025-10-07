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

    int nA, nB;
    std::cin >> nA >> nB;

    int k, m;
    std::cin >> k >> m;

    std::vector<long long> A(nA);
    for (int i = 0; i < nA; ++i) {
        std::cin >> A[i];
    }

    std::vector<long long> B(nB);
    for (int i = 0; i < nB; ++i) {
        std::cin >> B[i];
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end(), std::greater<long long>());

    if (A[k - 1] < B[m - 1]) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}
