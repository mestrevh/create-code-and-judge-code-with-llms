/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int k;
    std::cin >> k;

    if (k <= 0) {
        return 0;
    }

    std::vector<std::vector<long long>> triangle(k);

    for (int i = 0; i < k; ++i) {
        triangle[i].resize(i + 1);
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << triangle[i][j];
            if (j < i) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
