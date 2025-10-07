/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char board[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> board[i][j];
        }
    }

    int n;
    cin >> n;

    bool game_over = false;

    for (int k = 0; k < n; ++k) {
        char symbol;
        int row, col;
        cin >> symbol >> row >> col;

        if (game_over) {
            continue;
        }

        string player_name = (symbol == 'X') ? "Eduardo" : "Leonardo";

        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            cout << "O Dark Souls afetou sua cabeça? Jogue dentro das demarcações do jogo.\n";
            continue;
        }

        if (board[row][col] != '*') {
            cout << player_name << " não trapacei ou então vamos voltar a jogar Dark Souls.\n";
            continue;
        }

        board[row][col] = symbol;
        cout << player_name << " efetuou sua jogada com sucesso.\n";

        string win_location = "";
        bool has_won = false;

        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
                win_location = "linha " + to_string(i + 1);
                has_won = true;
                break;
            }
        }

        if (!has_won) {
            for (int j = 0; j < 3; ++j) {
                if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
                    win_location = "coluna " + to_string(j + 1);
                    has_won = true;
                    break;
                }
            }
        }

        if (!has_won) {
            if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
                win_location = "diagonal principal";
                has_won = true;
            } else if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
                win_location = "diagonal secundaria";
                has_won = true;
            }
        }

        if (has_won) {
            cout << player_name << " ganhou o jogo na " << win_location << ".\n";
            game_over = true;
        }
    }

    if (!game_over) {
        cout << "Nem no jogo da velha conseguimos ganhar algo, vamos voltar para o Dark Souls.\n";
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << (j == 2 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
