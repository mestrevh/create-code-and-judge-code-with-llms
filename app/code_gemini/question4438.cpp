/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << "NAO HA CELEBRIDADE" << std::endl;
        return 0;
    }

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int celebrity_candidate = -1;

    for (int i = 0; i < n; ++i) {
        bool is_celebrity = true;

        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (matrix[i][j] == 1) {
                is_celebrity = false;
                break;
            }
        }

        if (!is_celebrity) {
            continue;
        }

        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (matrix[j][i] == 0) {
                is_celebrity = false;
                break;
            }
        }

        if (is_celebrity) {
            celebrity_candidate = i;
            break;
        }
    }

    if (celebrity_candidate != -1) {
        std::cout << celebrity_candidate << std::endl;
    } else {
        std::cout << "NAO HA CELEBRIDADE" << std::endl;
    }

    return 0;
}
