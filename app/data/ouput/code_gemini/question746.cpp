/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, o;
    std::cin >> n >> m >> o;

    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }

    std::vector<std::vector<int>> b(m, std::vector<int>(o));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < o; ++j) {
            std::cin >> b[i][j];
        }
    }

    std::vector<std::vector<int>> c(n, std::vector<int>(o, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < o; ++j) {
            for (int k = 0; k < m; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < o; ++j) {
            std::cout << c[i][j] << (j == o - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}
