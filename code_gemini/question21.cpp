/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    for (int i = n; i <= m; ++i) {
        if (i % 2 != 0) {
            std::cout << i << "\n";
        }
    }
    return 0;
}
