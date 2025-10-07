/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int countEvenItems(const std::vector<std::vector<int>>& M, int L, int C) {
    int count = 0;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            if (M[i][j] % 2 == 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int L, C;
    std::cin >> L >> C;

    std::vector<std::vector<int>> M(L, std::vector<int>(C));

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cin >> M[i][j];
        }
    }

    int result = countEvenItems(M, L, C);
    std::cout << result << std::endl;

    return 0;
}
