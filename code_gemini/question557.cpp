/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <climits>

void print_optimal_parens(int i, int j, const std::vector<std::vector<int>>& s) {
    if (i == j) {
        std::cout << "A" << i;
    } else {
        std::cout << "(";
        print_optimal_parens(i, s[i][j], s);
        std::cout << " x ";
        print_optimal_parens(s[i][j] + 1, j, s);
        std::cout << ")";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int case_num = 1;
    while (std::cin >> n && n != 0) {
        std::vector<int> p(n + 1);
        for (int i = 0; i < n; ++i) {
            int r, c;
            std::cin >> r >> c;
            p[i] = r;
            p[i + 1] = c;
        }

        std::vector<std::vector<long long>> m(n + 1, std::vector<long long>(n + 1, 0));
        std::vector<std::vector<int>> s(n + 1, std::vector<int>(n + 1, 0));

        for (int len = 2; len <= n; ++len) {
            for (int i = 1; i <= n - len + 1; ++i) {
                int j = i + len - 1;
                m[i][j] = LLONG_MAX;
                for (int k = i; k < j; ++k) {
                    long long cost = m[i][k] + m[k + 1][j] + (long long)p[i - 1] * p[k] * p[j];
                    if (cost < m[i][j]) {
                        m[i][j] = cost;
                        s[i][j] = k;
                    }
                }
            }
        }

        std::cout << "Case " << case_num++ << ": ";
        print_optimal_parens(1, n, s);
        std::cout << "\n";
    }

    return 0;
}
