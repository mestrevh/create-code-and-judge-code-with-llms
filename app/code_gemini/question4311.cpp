/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int Ai, Aj, Bi, Bj;
    std::cin >> Ai >> Aj >> Bi >> Bj;

    if (Aj != Bi) {
        std::cout << "Nao e possivel multiplicar\n";
        return 0;
    }

    std::vector<std::vector<int>> A(Ai, std::vector<int>(Aj));
    std::vector<std::vector<int>> B(Bi, std::vector<int>(Bj));

    for (int i = 0; i < Ai; ++i) {
        for (int j = 0; j < Aj; ++j) {
            std::cin >> A[i][j];
        }
    }

    for (int i = 0; i < Bi; ++i) {
        for (int j = 0; j < Bj; ++j) {
            std::cin >> B[i][j];
        }
    }

    std::vector<std::vector<int>> C(Ai, std::vector<int>(Bj, 0));

    for (int i = 0; i < Ai; ++i) {
        for (int j = 0; j < Bj; ++j) {
            for (int k = 0; k < Aj; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < Ai; ++i) {
        for (int j = 0; j < Bj; ++j) {
            std::cout << C[i][j] << (j == Bj - 1 ? "" : " ");
        }
        std::cout << '\n';
    }

    return 0;
}
