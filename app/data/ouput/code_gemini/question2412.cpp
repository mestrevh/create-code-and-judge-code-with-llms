/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, e;
    std::cin >> n >> e;
    std::vector<int> g(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> g[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (g[i] + g[j] == e) {
                std::cout << "SIM" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "NAO" << std::endl;
    return 0;
}
