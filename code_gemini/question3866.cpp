/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long power(int base, int exp) {
    long long res = 1;
    for (int i = 0; i < exp; ++i) {
        res *= base;
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    long long mat[12][12];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        int ratio = -1;

        for (int j = 1; j < m; ++j) {
            if (mat[i][j] != -1) {
                for (int test_r = 1; test_r <= 11; ++test_r) {
                    if (power(test_r, j) == mat[i][j]) {
                        ratio = test_r;
                        break;
                    }
                }
            }
            if (ratio != -1) {
                break;
            }
        }

        long long current_power = 1;
        for (int j = 0; j < m; ++j) {
            mat[i][j] = current_power;
            current_power *= ratio;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << mat[i][j] << (j == m - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}
