/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val = std::min(i, j) + 1;
            std::cout << val << (j == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}