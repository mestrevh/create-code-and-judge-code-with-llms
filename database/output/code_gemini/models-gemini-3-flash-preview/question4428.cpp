/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, targetR, targetC;
    while (cin >> N >> targetR >> targetC) {
        vector<vector<int>> mat(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> mat[i][j];
            }
        }

        if (targetR < 0 || targetR >= N || targetC < 0 || targetC >= N) {
            cout << "Numero de passos do maior caminho: 0" << endl;
            continue;
        }

        vector<vector<int>> dist(N, vector<int>(N, -1));
        queue<pair<int, int>> q;

        q.push({targetR, targetC});
        dist[targetR][targetC] = 0;

        int max_steps = 0;
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            int r = curr.first;
            int c = curr.second;

            if (dist[r][c] > max_steps) {
                max_steps = dist[r][c];
            }

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                    if (mat[nr][nc] == mat[r][c] - 1) {
                        if (dist[nr][nc] == -1) {
                            dist[nr][nc] = dist[r][c] + 1;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }

        cout << "Numero de passos do maior caminho: " << max_steps << endl;
    }

    return 0;
}