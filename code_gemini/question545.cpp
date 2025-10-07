/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<long long> T;

void bst_init(const std::vector<long long>& X, long long a, long long b) {
    if (a > b) {
        return;
    }
    long long c = a + (b - a) / 2;
    T.insert(X[c]);
    bst_init(X, a, c - 1);
    bst_init(X, c + 1, b);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long N, seedY, z, w, modY, seedX, modX;
    std::cin >> N >> seedY >> z >> w >> modY >> seedX >> modX;

    if (N > 0) {
        std::vector<long long> Y(N);
        std::vector<long long> X(N);
        
        Y[0] = seedY;
        for (long long i = 1; i < N; ++i) {
            Y[i] = (Y[i - 1] * z + w) % modY;
        }

        X[0] = seedX;
        for (long long i = 1; i < N; ++i) {
            X[i] = X[i - 1] + 1 + (Y[i - 1] % modX);
        }
        
        bst_init(X, 0, N - 1);
    }

    std::string command;
    while (std::cin >> command) {
        if (command == "ADD") {
            long long k;
            std::cin >> k;
            if (T.find(k) == T.end()) {
                T.insert(k);
                std::cout << 1 << "\n";
            } else {
                std::cout << 0 << "\n";
            }
        } else if (command == "DEL") {
            long long k;
            std::cin >> k;
            std::cout << T.erase(k) << "\n";
        } else if (command == "INT") {
            long long a, b;
            std::cin >> a >> b;
            if (a > b) {
                std::cout << 0 << "\n";
            } else {
                std::cout << (T.order_of_key(b + 1) - T.order_of_key(a)) << "\n";
            }
        } else if (command == "SGE") {
            if (T.size() < 2) {
                std::cout << -1 << "\n";
            } else {
                std::cout << *T.find_by_order(T.size() - 2) << "\n";
            }
        }
    }

    return 0;
}
