/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int N, A, L;
vector<string> words;
vector<string> grid;
vector<vector<bool>> used;
vector<vector<pair<int, int>>> solutions;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool solve(int word_idx, int char_idx, int prev_r, int prev_c) {
    if (word_idx == N) {
        return true;
    }

    if (char_idx == (int)words[word_idx].length()) {
        return solve(word_idx + 1, 0, -1, -1);
    }

    if (char_idx == 0) {
        for (int r = 0; r < A; ++r) {
            for (int c = 0; c < L; ++c) {
                if (!used[r][c] && grid[r][c] == words[word_idx][0]) {
                    used[r][c] = true;
                    solutions[word_idx].push_back({r, c});
                    if (solve(word_idx, 1, r, c)) {
                        return true;
                    }
                    solutions[word_idx].pop_back();
                    used[r][c] = false;
                }
            }
        }
    } else {
        for (int i = 0; i < 4; ++i) {
            int nr = prev_r + dr[i];
            int nc = prev_c + dc[i];

            if (nr >= 0 && nr < A && nc >= 0 && nc < L && !used[nr][nc] && grid[nr][nc] == words[word_idx][char_idx]) {
                used[nr][nc] = true;
                solutions[word_idx].push_back({nr, nc});
                if (solve(word_idx, char_idx + 1, nr, nc)) {
                    return true;
                }
                solutions[word_idx].pop_back();
                used[nr][nc] = false;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool first_case = true;

    while (cin >> N >> A >> L && (N || A || L)) {
        if (!first_case) {
            cout << endl;
        }
        first_case = false;

        vector<pair<string, int>> indexed_words(N);
        for (int i = 0; i < N; ++i) {
            cin >> indexed_words[i].first;
            indexed_words[i].second = i;
        }

        sort(indexed_words.begin(), indexed_words.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.first.length() > b.first.length();
        });

        words.resize(N);
        vector<int> original_indices(N);
        for (int i = 0; i < N; ++i) {
            words[i] = indexed_words[i].first;
            original_indices[i] = indexed_words[i].second;
        }

        grid.assign(A, "");
        for (int i = 0; i < A; ++i) {
            cin >> grid[i];
        }

        used.assign(A, vector<bool>(L, false));
        solutions.assign(N, vector<pair<int, int>>());

        if (solve(0, 0, -1, -1)) {
            vector<vector<pair<int, int>>> final_solutions(N);
            for (int i = 0; i < N; ++i) {
                final_solutions[original_indices[i]] = solutions[i];
            }

            for (int i = 0; i < N; ++i) {
                for (size_t j = 0; j < final_solutions[i].size(); ++j) {
                    cout << (final_solutions[i][j].first + 1) << (final_solutions[i][j].second + 1);
                    if (j < final_solutions[i].size() - 1) {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
    }

    return 0;
}
