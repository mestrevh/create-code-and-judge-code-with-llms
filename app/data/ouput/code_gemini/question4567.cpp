/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M, A, B;
    std::cin >> N >> M >> A >> B;

    if (M != A) {
        std::cout << "Nao eh possivel multiplicar!\n";
        return 0;
    }

    std::vector<std::vector<int>> mat1(N, std::vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> mat1[i][j];
        }
    }

    std::vector<std::vector<int>> mat2(A, std::vector<int>(B));
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < B; ++j) {
            std::cin >> mat2[i][j];
        }
    }

    std::vector<std::vector<int>> result(N, std::vector<int>(B, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < B; ++j) {
            for (int k = 0; k < M; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < B; ++j) {
            std::cout << result[i][j] << (j == B - 1 ? "" : " ");
        }
        std::cout << '\n';
    }

    return 0;
}
