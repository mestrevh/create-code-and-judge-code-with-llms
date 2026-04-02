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

    int M, N;
    if (!(cin >> M >> N)) return 0;

    vector<string> grid(M);
    for (int i = 0; i < M; ++i) {
        cin >> grid[i];
    }

    int coast_count = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == '#') {
                bool is_coast = false;
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni < 0 || ni >= M || nj < 0 || nj >= N) {
                        is_coast = true;
                        break;
                    } else if (grid[ni][nj] == '.') {
                        is_coast = true;
                        break;
                    }
                }
                if (is_coast) {
                    coast_count++;
                }
            }
        }
    }

    cout << coast_count << endl;

    return 0;
}