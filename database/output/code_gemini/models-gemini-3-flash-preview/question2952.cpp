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

    int K;
    if (!(cin >> K)) return 0;

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<string> grid(N);
    int total_o = 0;
    for (int i = 0; i < N; ++i) {
        if (!(cin >> grid[i])) break;
        for (char c : grid[i]) {
            if (c == 'o') total_o++;
        }
    }

    bool found_together = false;
    int bestRow = -1;
    int bestColStart = -1;

    if (K > 0) {
        for (int i = 0; i < N; ++i) {
            int consecutive = 0;
            for (int j = M - 1; j >= 0; --j) {
                if (grid[i][j] == 'o') {
                    consecutive++;
                    if (consecutive >= K) {
                        bestRow = i;
                        bestColStart = j;
                        found_together = true;
                        break;
                    }
                } else {
                    consecutive = 0;
                }
            }
            if (found_together) break;
        }
    } else {
        found_together = true;
    }

    if (found_together) {
        cout << "Todos sentados e juntos\n";
        if (K > 0 && bestRow != -1) {
            for (int l = 0; l < K; ++l) {
                grid[bestRow][bestColStart + l] = '*';
            }
        }
    } else if (total_o >= K) {
        cout << "Todos sentados, mas separados\n";
        int count = 0;
        for (int i = 0; i < N && count < K; ++i) {
            for (int j = M - 1; j >= 0 && count < K; --j) {
                if (grid[i][j] == 'o') {
                    grid[i][j] = '*';
                    count++;
                }
            }
        }
    } else {
        cout << total_o << " sentados, " << (K - total_o) << " em pé\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == 'o') {
                    grid[i][j] = '*';
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << grid[i] << "\n";
    }

    return 0;
}