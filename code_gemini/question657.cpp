/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int k;
    while (std::cin >> k && k != 0) {
        int n, m;
        std::cin >> n >> m;
        for (int i = 0; i < k; ++i) {
            int x, y;
            std::cin >> x >> y;
            if (x == n || y == m) {
                std::cout << "divisa\n";
            } else if (x > n && y > m) {
                std::cout << "NE\n";
            } else if (x < n && y > m) {
                std::cout << "NO\n";
            } else if (x < n && y < m) {
                std::cout << "SO\n";
            } else {
                std::cout << "SE\n";
            }
        }
    }
    return 0;
}
