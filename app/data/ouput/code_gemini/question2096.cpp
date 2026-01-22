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

    std::vector<std::vector<int>> boardA(9, std::vector<int>(9));
    std::vector<std::vector<int>> boardB(9, std::vector<int>(9));

    int shipsA = 0;
    int shipsB = 0;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cin >> boardA[i][j];
            if (boardA[i][j] == 1) {
                shipsA++;
            }
        }
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cin >> boardB[i][j];
            if (boardB[i][j] == 1) {
                shipsB++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::string move;
        std::cin >> move;

        int row = move[0] - 'A';
        int col = move[1] - '1';

        if (i % 2 == 0) {
            if (boardB[row][col] == 1) {
                boardB[row][col] = 0;
                shipsB--;
            }
        } else {
            if (boardA[row][col] == 1) {
                boardA[row][col] = 0;
                shipsA--;
            }
        }
    }

    if (shipsA > shipsB) {
        std::cout << "O jogador A venceu\n";
    } else if (shipsB > shipsA) {
        std::cout << "O jogador B venceu\n";
    } else {
        std::cout << "Empate\n";
    }

    return 0;
}
