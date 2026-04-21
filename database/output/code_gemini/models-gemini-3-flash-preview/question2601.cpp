/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char board[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!(cin >> board[i][j])) break;
        }
    }

    int n;
    if (!(cin >> n)) n = 0;

    bool won = false;
    for (int i = 0; i < n; ++i) {
        char c;
        int x, y;
        if (!(cin >> c >> x >> y)) break;

        if (won) continue;

        string name = (c == 'X' ? "Eduardo" : "Leonardo");

        if (x < 0 || x > 2 || y < 0 || y > 2) {
            cout << "O Dark Souls afetou sua cabeça? Jogue dentro das demarcações do jogo.\n";
        } else if (board[x][y] != '*') {
            cout << name << " não trapacei ou então vamos voltar a jogar Dark Souls.\n";
        } else {
            board[x][y] = c;
            cout << name << " efetuou sua jogada com sucesso.\n";

            string loc = "";
            // Check win conditions in order specified: linha 1, 2, 3, coluna 1, 2, 3, diagonal principal, secundaria
            if (board[0][0] != '*' && board[0][0] == board[0][1] && board[0][1] == board[0][2]) loc = "linha 1";
            else if (board[1][0] != '*' && board[1][0] == board[1][1] && board[1][1] == board[1][2]) loc = "linha 2";
            else if (board[2][0] != '*' && board[2][0] == board[2][1] && board[2][1] == board[2][2]) loc = "linha 3";
            else if (board[0][0] != '*' && board[0][0] == board[1][0] && board[1][0] == board[2][0]) loc = "coluna 1";
            else if (board[0][1] != '*' && board[0][1] == board[1][1] && board[1][1] == board[2][1]) loc = "coluna 2";
            else if (board[0][2] != '*' && board[0][2] == board[1][2] && board[1][2] == board[2][2]) loc = "coluna 3";
            else if (board[0][0] != '*' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) loc = "diagonal principal";
            else if (board[0][2] != '*' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) loc = "diagonal secundaria";

            if (loc != "") {
                cout << name << " ganhou o jogo na " << loc << ".\n";
                won = true;
            }
        }
    }

    if (!won) {
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