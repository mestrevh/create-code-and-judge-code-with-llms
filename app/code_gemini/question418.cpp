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
    std::cin >> n;

    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 1);

    do {
        for (int i = 0; i < n; ++i) {
            std::cout << p[i];
        }
        std::cout << "\n";
    } while (std::next_permutation(p.begin(), p.end()));

    return 0;
}
