/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, best_sum, max_val;
int grid[55][55];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
bool used[2505];

void redelmeier(int count, int current_sum, vector<int> candidates, int root_idx) {
    if (count == M) {
        if (current_sum > best_sum) {
            best_sum = current_sum;
        }
        return;
    }

    if (current_sum + (M - count) * max_val <= best_sum) {
        return;
    }

    if (candidates.empty()) {
        return;
    }

    vector<int> skipped;
    while (!candidates.empty()) {
        int v = candidates.back();
        candidates.pop_back();

        int r = v / N;
        int c = v % N;
        
        vector<int> next_candidates = candidates;
        vector<int> added;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                int nv = nr * N + nc;
                if (nv > root_idx && !used[nv]) {
                    used[nv] = true;
                    next_candidates.push_back(nv);
                    added.push_back(nv);
                }
            }
        }

        redelmeier(count + 1, current_sum + grid[r][c], next_candidates, root_idx);

        for (int nv : added) {
            used[nv] = false;
        }
        skipped.push_back(v);
    }

    for (int v : skipped) {
        used[v] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> M)) return 0;

    max_val = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] > max_val) {
                max_val = grid[i][j];
            }
        }
    }

    best_sum = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            int root_idx = r * N + c;
            
            for (int i = 0; i < N * N; ++i) {
                used[i] = false;
            }
            used[root_idx] = true;

            vector<int> initial_candidates;
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                    int nv = nr * N + nc;
                    if (nv > root_idx) {
                        used[nv] = true;
                        initial_candidates.push_back(nv);
                    }
                }
            }

            redelmeier(1, grid[r][c], initial_candidates, root_idx);
        }
    }

    cout << best_sum << endl;

    return 0;
}