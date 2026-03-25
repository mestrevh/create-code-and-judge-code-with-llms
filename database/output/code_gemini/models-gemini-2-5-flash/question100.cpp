/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

// Função para verificar se um jogador venceu
bool checkWinner(char player, const std::vector<std::vector<char>>& board) {
    // Verificar linhas
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Verificar colunas
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    // Verificar diagonais
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

int main() {
    // Otimização padrão de I/O em C++
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num_games;
    std::cin >> num_games;

    while (num_games--) {
        std::vector<std::vector<char>> board(3, std::vector<char>(3));
        int countX = 0;
        int countO = 0;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cin >> board[i][j];
                if (board[i][j] == 'X') {
                    countX++;
                } else if (board[i][j] == 'O') {
                    countO++;
                }
            }
        }

        bool xWins = checkWinner('X', board);
        bool oWins = checkWinner('O', board);

        // Cenário 1: Ambos os jogadores venceram simultaneamente (impossível em um jogo legal)
        if (xWins && oWins) {
            std::cout << "ILEGAL\n";
        } 
        // Cenário 2: X venceu
        else if (xWins) {
            // Se X venceu, X deve ter feito a última jogada.
            // Isso significa que countX deve ser exatamente countO + 1.
            // Qualquer outra contagem (e.g., countX == countO ou countX > countO + 1)
            // é ilegal, pois implica que O jogou por último ou X jogou mais de uma vez.
            if (countX == countO + 1) {
                std::cout << "X_VENCEU\n";
            } else {
                std::cout << "ILEGAL\n";
            }
        } 
        // Cenário 3: O venceu
        else if (oWins) {
            // Se O venceu, O deve ter feito a última jogada.
            // Isso significa que countX deve ser exatamente countO.
            // countX não pode ser maior que countO (X jogou por último).
            // countX não pode ser menor que countO (O começou ou jogou mais).
            if (countX == countO) {
                std::cout << "O_VENCEU\n";
            } else {
                std::cout << "ILEGAL\n";
            }
        } 
        // Cenário 4: Ninguém venceu (o jogo pode estar em andamento ou ser ilegal por contagem de jogadas)
        else {
            // Verificação de ilegalidade de contagem de jogadas para jogos sem vencedor:
            // - O não pode ter mais jogadas que X (X sempre começa).
            // - X não pode ter mais de uma jogada extra que O.
            // Ou seja, countX deve ser countO ou countO + 1.
            if (countO > countX || countX > countO + 1) {
                std::cout << "ILEGAL\n";
            } else {
                // Se a contagem de jogadas é válida e não há vencedor:
                // Se o tabuleiro estiver cheio (9 casas ocupadas), é um empate.
                // Conforme a regra: "em caso de empate considere que o jogo está em andamento".
                if (countX + countO == 9) {
                    std::cout << "EM_ANDAMENTO\n";
                } else {
                    // Caso contrário, o jogo está em andamento.
                    std::cout << "EM_ANDAMENTO\n";
                }
            }
        }
    }

    return 0;
}