/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int k;
    if (!(std::cin >> k) || k <= 0) {
        return 0;
    }

    std::vector<std::vector<unsigned long long>> triangle(k);

    for (int i = 0; i < k; ++i) {
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                triangle[i][j] = 1;
            } else {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            
            std::cout << triangle[i][j];
            if (j < i) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}