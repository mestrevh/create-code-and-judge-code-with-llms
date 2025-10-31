/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    int case_num = 1;
    while (std::cin >> n >> m) {
        std::vector<int> a(n + 1);
        for (int i = 0; i <= n; ++i) {
            std::cin >> a[i];
        }

        std::vector<int> b(m + 1);
        for (int i = 0; i <= m; ++i) {
            std::cin >> b[i];
        }

        std::vector<long long> c(n + m + 1, 0);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                c[i + j] += (long long)a[i] * b[j];
            }
        }

        std::cout << "Caso #" << case_num++ << ":";
        for (int i = 0; i <= n + m; ++i) {
            std::cout << " " << c[i];
        }
        std::cout << "\n";
    }
    return 0;
}
