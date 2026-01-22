/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

void transformaPares(std::vector<int>& L) {
    for (int& elemento : L) {
        if (elemento % 2 == 0) {
            elemento++;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        return 0;
    }

    std::vector<int> L(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> L[i];
    }

    transformaPares(L);

    for (const int& elemento : L) {
        std::cout << elemento << "\n";
    }

    return 0;
}
