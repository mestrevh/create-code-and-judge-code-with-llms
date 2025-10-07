/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int L, C, N;
    std::cin >> L >> C >> N;

    std::vector<std::vector<int>> board(L, std::vector<int>(C));
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cin >> board[i][j];
        }
    }

    int effective_N = (N % 4 + 4) % 4;

    if (effective_N == 0) {
        // 0 graus
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < C; ++j) {
                std::cout << board[i][j] << (j == C - 1 ? "" : " ");
            }
            std::cout << "\n";
        }
    } else if (effective_N == 1) {
        // 90 graus horario
        for (int i = 0; i < C; ++i) {
            for (int j = L - 1; j >= 0; --j) {
                std::cout << board[j][i] << (j == 0 ? "" : " ");
            }
            std::cout << "\n";
        }
    } else if (effective_N == 2) {
        // 180 graus
        for (int i = L - 1; i >= 0; --i) {
            for (int j = C - 1; j >= 0; --j) {
                std::cout << board[i][j] << (j == 0 ? "" : " ");
            }
            std::cout << "\n";
        }
    } else { // effective_N == 3
        // 270 graus horario (ou 90 anti-horario)
        for (int i = C - 1; i >= 0; --i) {
            for (int j = 0; j < L; ++j) {
                std::cout << board[j][i] << (j == L - 1 ? "" : " ");
            }
            std::cout << "\n";
        }
    }

    return 0;
}
