/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

void solve() {
    long long N, K;
    if (!(std::cin >> N >> K)) {
        return;
    }

    std::vector<long long> L(K);
    for (int i = 0; i < K; ++i) {
        std::cin >> L[i];
    }

    if (K == 1) {
        if (L[0] <= N) {
            std::cout << "S\n";
        } else {
            std::cout << "N\n";
        }
        return;
    }

    bool possible = true;

    for (int i = 0; i < K - 1; ++i) {
        long long diff = std::abs(L[i] - L[i + 1]);
        if (diff != 1 && diff != 2) {
            possible = false;
            break;
        }
        if (L[i] < 3 && L[i + 1] < L[i]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        for (int i = 1; i < K - 1; ++i) {
            if (L[i + 1] == L[i - 1]) {
                possible = false;
                break;
            }
            if (L[i] < L[i - 1] && L[i] < L[i + 1]) {
                possible = false;
                break;
            }
            if (L[i] > L[i - 1] && L[i] > L[i + 1]) {
                if (L[i - 1] + L[i + 1] != 2 * L[i] - 3) {
                    possible = false;
                    break;
                }
            }
        }
    }

    if (!possible) {
        std::cout << "N\n";
        return;
    }

    long long req1 = std::numeric_limits<long long>::max();
    if (L[0] > L[1]) {
        req1 = L[0];
        for (int i = 1; i < K - 1; ++i) {
            if (L[i] < L[i + 1]) {
                req1 = std::max(req1, L[i + 1]);
            }
        }
    }

    long long req2 = std::numeric_limits<long long>::max();
    if (L[0] < L[1]) {
        req2 = L[1];
        for (int i = 1; i < K - 1; ++i) {
            if (L[i] < L[i + 1]) {
                req2 = std::max(req2, L[i + 1]);
            }
        }
    }

    if (std::min(req1, req2) <= N) {
        std::cout << "S\n";
    } else {
        std::cout << "N\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (std::cin.peek() != EOF && std::cin.peek() != '\n') {
        solve();
    }
    return 0;
}
