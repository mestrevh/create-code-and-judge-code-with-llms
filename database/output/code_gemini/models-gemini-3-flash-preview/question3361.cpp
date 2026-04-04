/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    for (int i = 1; i <= n; ++i) {
        if (i % 10 != 0) {
            std::cout << i << "\n";
        }
    }

    return 0;
}