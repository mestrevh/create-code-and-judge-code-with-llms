/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> grid(6, vector<int>(7, 0));
    vector<int> moves;
    moves.reserve(42);

    int x;
    while (cin >> x) moves.push_back(x);
    if (moves.size() < 42) moves.resize(42, 0);

    int winner = 0;
    for (int i = 0; i < 42; i++) {
        int col = moves[i];
        int player = (i % 2 == 0) ? 1 : 2;
        int r = -1;
        for (int rr = 5; rr >= 0; rr--) {
            if (grid[rr][col] == 0) {
                r = rr;
                break;
            }
        }
        if (r != -1) grid[r][col] = player;

        auto checkFrom = [&](int pr, int pc) -> int {
            int val = grid[pr][pc];
            if (!val) return 0;
            const int dr[4] = {0, 1, 1, 1};
            const int dc[4] = {1, 0, 1, -1};
            for (int d = 0; d < 4; d++) {
                int cnt = 1;
                int rr = pr + dr[d], cc = pc + dc[d];
                while (rr >= 0 && rr < 6 && cc >= 0 && cc < 7 && grid[rr][cc] == val) {
                    cnt++;
                    rr += dr[d];
                    cc += dc[d];
                }
                rr = pr - dr[d]; cc = pc - dc[d];
                while (rr >= 0 && rr < 6 && cc >= 0 && cc < 7 && grid[rr][cc] == val) {
                    cnt++;
                    rr -= dr[d];
                    cc -= dc[d];
                }
                if (cnt >= 4) return val;
            }
            return 0;
        };

        if (winner == 0 && r != -1) {
            int w = checkFrom(r, col);
            if (w) winner = w;
        }
    }

    if (winner == 2) cout << "Jogador 2 Venceu!\n";
    else if (winner == 1) cout << "Jogador 1 Venceu!\n";
    else cout << "Empate!\n";

    cout << "Estado Final do Jogo:\n";
    for (int i = 0; i < 6; i++) {
        cout << "|";
        for (int j = 0; j < 7; j++) {
            cout << " " << grid[i][j];
        }
        cout << " |\n";
    }

    return 0;
}