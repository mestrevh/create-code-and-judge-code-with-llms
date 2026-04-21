/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int grid[205][205]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, X, Y, K;
    if (!(cin >> N >> M >> X >> Y >> K)) return 0;

    for (int i = 0; i < K; ++i) {
        int a, b;
        cin >> a >> b;
        if (a >= 1 && a <= N && b >= 1 && b <= M) {
            grid[a][b] = 1;
        }
    }

    int painted = 0;
    queue<pair<int, int>> q;
    if (X >= 1 && X <= N && Y >= 1 && Y <= M && grid[X][Y] == 0) {
        q.push({X, Y});
        grid[X][Y] = 2;
    }

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        painted++;

        int r = curr.first;
        int c = curr.second;

        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                if (dr == 0 && dc == 0) continue;
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 1 && nr <= N && nc >= 1 && nc <= M && grid[nr][nc] == 0) {
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }
        }
    }

    cout << painted << endl;

    return 0;
}