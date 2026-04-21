/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstdio>

using namespace std;

struct Node {
    int r, c, d;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string size_str;
    if (!(cin >> size_str)) return 0;

    int R, C;
    sscanf(size_str.c_str(), "%dx%d", &R, &C);

    vector<string> grid(R);
    int start_r = -1, start_c = -1;
    int end_r = -1, end_c = -1;

    for (int i = 0; i < R; ++i) {
        cin >> grid[i];
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 'o') {
                start_r = i;
                start_c = j;
            } else if (grid[i][j] == 'd') {
                end_r = i;
                end_c = j;
            }
        }
    }

    if (start_r == -1 || end_r == -1) {
        cout << "Poxa... Parece que nao foi dessa vez que Rebeka conseguiu fugir" << endl;
        return 0;
    }

    queue<Node> q;
    q.push({start_r, start_c, 0});
    
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    visited[start_r][start_c] = true;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    int result = -1;
    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        if (current.r == end_r && current.c == end_c) {
            result = current.d;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = current.r + dr[i];
            int nc = current.c + dc[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C && !visited[nr][nc] && grid[nr][nc] != '#') {
                visited[nr][nc] = true;
                q.push({nr, nc, current.d + 1});
            }
        }
    }

    if (result != -1) {
        cout << "Apos correr " << result << " metros e quase desistir por causa da distância, Rebeka conseguiu escapar!" << endl;
    } else {
        cout << "Poxa... Parece que nao foi dessa vez que Rebeka conseguiu fugir" << endl;
    }

    return 0;
}