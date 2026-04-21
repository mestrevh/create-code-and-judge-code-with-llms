/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;
    if (N <= 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> total_moves(N, vector<int>(N, 0));
    vector<vector<int>> current_dist(N, vector<int>(N, 0));
    
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int d = 0; d < 8; ++d) {
        int cur_dx = dx[d];
        int cur_dy = dy[d];

        int i_start = (cur_dx == 1) ? N - 1 : 0;
        int i_end = (cur_dx == 1) ? -1 : N;
        int i_step = (cur_dx == 1) ? -1 : 1;

        int j_start = (cur_dy == 1) ? N - 1 : 0;
        int j_end = (cur_dy == 1) ? -1 : N;
        int j_step = (cur_dy == 1) ? -1 : 1;

        for (int i = i_start; i != i_end; i += i_step) {
            for (int j = j_start; j != j_end; j += j_step) {
                if (grid[i][j] == 0) {
                    int ni = i + cur_dx;
                    int nj = j + cur_dy;
                    if (ni >= 0 && ni < N && nj >= 0 && nj < N && grid[ni][nj] == 0) {
                        current_dist[i][j] = current_dist[ni][nj] + 1;
                    } else {
                        current_dist[i][j] = 0;
                    }
                    total_moves[i][j] += current_dist[i][j];
                } else {
                    current_dist[i][j] = 0;
                }
            }
        }
    }

    int max_score = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == 0) {
                if (total_moves[i][j] > max_score) {
                    max_score = total_moves[i][j];
                }
            }
        }
    }

    cout << max_score << endl;

    return 0;
}