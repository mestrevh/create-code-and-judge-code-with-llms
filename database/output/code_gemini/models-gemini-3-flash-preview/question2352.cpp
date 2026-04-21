/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

void transformar(std::vector<int>& L, int n) {
    for (int i = 0; i < n; ++i) {
        if (L[i] % 2 == 0) {
            L[i] = L[i] + 1;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    if (n < 1) return 0;

    std::vector<int> L(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> L[i];
    }

    transformar(L, n);

    for (int i = 0; i < n; ++i) {
        std::cout << L[i] << "\n";
    }

    return 0;
}