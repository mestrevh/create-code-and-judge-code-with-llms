/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char board[8][8];
    int r = -1, c = -1;

    // Read the 8x8 checkers board
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (!(cin >> board[i][j])) break;
            if (board[i][j] == '#') {
                r = i;
                c = j;
            }
        }
    }

    int N;
    if (!(cin >> N)) N = 0;
    int captures = 0;
    bool sopro_occurred = false;

    for (int k = 0; k < N; ++k) {
        char cmd;
        cin >> cmd;

        // If a "sopro" has already occurred, ignore subsequent commands
        if (sopro_occurred) continue;

        // tr, tc: square diagonally in front of current position
        // jr, jc: square two units diagonally in front (the jump target)
        int tr = r - 1;
        int tc = (cmd == 'E' ? c - 1 : c + 1);
        int jr = r - 2;
        int jc = (cmd == 'E' ? c - 2 : c + 2);

        // Check if any capture was possible from the *current* position
        int sr = -1, sc = -1;
        bool possible_capture_anywhere = false;
        
        // Check left capture possibility
        if (r - 2 >= 0 && c - 2 >= 0 && board[r - 1][c - 1] == '%' && board[r - 2][c - 2] == '*') {
            sr = r - 1; sc = c - 1;
            possible_capture_anywhere = true;
        }
        // Check right capture possibility (if left not already found)
        if (!possible_capture_anywhere && r - 2 >= 0 && c + 2 < 8 && board[r - 1][c + 1] == '%' && board[r - 2][c + 2] == '*') {
            sr = r - 1; sc = c + 1;
            possible_capture_anywhere = true;
        }

        // Logic for specific command 'D' or 'E'
        if (tr >= 0 && tr < 8 && tc >= 0 && tc < 8 && board[tr][tc] == '%') {
            // Attempt to capture in the direction specified by the command
            if (jr >= 0 && jr < 8 && jc >= 0 && jc < 8 && board[jr][jc] == '*') {
                // Successful capture
                cout << "Voce capturou uma peca na casa (" << tr << "," << tc << ") e avancou para a casa (" << jr << "," << jc << ")." << endl;
                board[r][c] = '*';
                board[tr][tc] = '*';
                board[jr][jc] = '#';
                r = jr; c = jc;
                captures++;
            } else {
                // Blocked capture (another piece behind it or off board)
                cout << "Voce nao pode capturar essa peca." << endl;
            }
        } else if (tr >= 0 && tr < 8 && tc >= 0 && tc < 8 && board[tr][tc] == '*') {
            // Normal move to an empty square
            cout << "Voce avancou para a casa (" << tr << "," << tc << ")." << endl;
            board[r][c] = '*';
            board[tr][tc] = '#';
            r = tr; c = tc;
            
            // Check for sopro: if a capture was possible, the player should have taken it
            if (possible_capture_anywhere) {
                cout << "Voce deveria ter capturado a peca na casa (" << sr << "," << sc << ")." << endl;
                sopro_occurred = true;
            }
        }
    }

    // Output the final state of the board
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << board[i][j] << (j == 7 ? "" : " ");
        }
        cout << endl;
    }

    // Output summary
    cout << "Voce capturou " << captures << " pecas." << endl;
    if (sopro_occurred) {
        cout << "Deu sopro." << endl;
    }

    return 0;
}