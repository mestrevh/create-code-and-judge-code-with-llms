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

    std::vector<std::vector<int>> board_a(9, std::vector<int>(9));
    std::vector<std::vector<int>> board_b(9, std::vector<int>(9));

    int ships_a = 0;
    int ships_b = 0;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cin >> board_a[i][j];
            if (board_a[i][j] == 1) {
                ships_a++;
            }
        }
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cin >> board_b[i][j];
            if (board_b[i][j] == 1) {
                ships_b++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::string move;
        std::cin >> move;

        int row = move[0] - 'A';
        int col = move[1] - '1';

        if (i % 2 == 0) {
            if (board_b[row][col] == 1) {
                board_b[row][col] = 0;
                ships_b--;
            }
        } else {
            if (board_a[row][col] == 1) {
                board_a[row][col] = 0;
                ships_a--;
            }
        }
    }

    if (ships_a > ships_b) {
        std::cout << "O jogador A venceu\n";
    } else if (ships_b > ships_a) {
        std::cout << "O jogador B venceu\n";
    } else {
        std::cout << "Empate\n";
    }

    return 0;
}
