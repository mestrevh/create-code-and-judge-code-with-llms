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

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<vector<char>> grid(N, vector<char>(M));
    int sr = -1, sc = -1, totalFruits = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') {
                sr = i;
                sc = j;
            } else if (grid[i][j] == 'O') {
                totalFruits++;
            }
        }
    }

    int mode;
    cin >> mode;
    string commands;
    if (!(cin >> commands)) {
        commands = "";
    }

    int eaten = 0;
    int status = 0; // 0: end of commands, 1: win, 2: lose

    if (totalFruits == 0) {
        status = 1;
    } else {
        for (char cmd : commands) {
            int nr = sr, nc = sc;
            if (cmd == 'N') nr--;
            else if (cmd == 'S') nr++;
            else if (cmd == 'L') nc++;
            else if (cmd == 'O') nc--;

            if (mode == 1) {
                if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                    status = 2;
                    break;
                }
            } else {
                nr = (nr % N + N) % N;
                nc = (nc % M + M) % M;
            }

            if (grid[nr][nc] == '%') {
                status = 2;
                break;
            }

            bool fruit = (grid[nr][nc] == 'O');
            if (fruit) {
                eaten++;
            }

            grid[sr][sc] = '.';
            sr = nr;
            sc = nc;
            grid[sr][sc] = '#';

            if (eaten == totalFruits) {
                status = 1;
                break;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << grid[i][j] << (j == M - 1 ? "" : " ");
        }
        cout << "\n";
    }
    cout << "\n";

    if (status == 1) {
        cout << "Parabens, voce venceu!\n";
    } else if (status == 2) {
        cout << " - GAME OVER - \n";
    }

    cout << "Numero de frutas comidas: " << eaten << "\n";

    return 0;
}