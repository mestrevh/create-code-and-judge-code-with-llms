/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<vector<char>> grid(N, vector<char>(M));
    int sr = -1, sc = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            string s;
            cin >> s;
            char c = s.empty() ? '.' : s[0];
            grid[i][j] = c;
            if (c == '%') { sr = i; sc = j; }
        }
    }

    int mode;
    cin >> mode;

    string commands;
    cin >> commands;

    int eaten = 0;
    bool gameOver = false;
    bool won = false;

    auto inb = [&](int r, int c) {
        return r >= 0 && r < N && c >= 0 && c < M;
    };

    int totalFruits = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (grid[i][j] == '%') totalFruits++;

    int r = sr, c = sc;
    for (char cmd : commands) {
        if (gameOver || won) break;

        int nr = r, nc = c;
        if (cmd == 'N') nr--;
        else if (cmd == 'S') nr++;
        else if (cmd == 'L') nc++;
        else if (cmd == 'O') nc--;

        if (!inb(nr, nc)) {
            if (mode == 1) {
                gameOver = true;
                break;
            } else {
                if (nr < 0) nr = N - 1;
                if (nr >= N) nr = 0;
                if (nc < 0) nc = M - 1;
                if (nc >= M) nc = 0;
            }
        }

        if (grid[nr][nc] == '#') {
            gameOver = true;
            break;
        }

        if (grid[nr][nc] == '%') {
            grid[nr][nc] = '.';
            eaten++;
        }

        r = nr; c = nc;

        if (eaten == totalFruits) {
            won = true;
            break;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i || j) cout << ' ';
            char outc = grid[i][j];
            if (outc == ' ') outc = '.';
            if (i == r && j == c) outc = (outc == '.' ? 'O' : outc);
            cout << outc;
        }
        cout << "\n";
    }

    if (gameOver) {
        cout << "\n - GAME OVER - \n";
        cout << "Numero de frutas comidas: " << eaten << "\n";
    } else if (won) {
        cout << "\nParabens, voce venceu!\n";
        cout << "Numero de frutas comidas: " << eaten << "\n";
    } else {
        cout << "\nNumero de frutas comidas: " << eaten << "\n";
    }

    return 0;
}