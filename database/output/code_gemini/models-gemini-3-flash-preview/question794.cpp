/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, A, L;
string words[25];
string grid[15];
bool used[15][15];

struct Pos {
    int r, l;
};

vector<Pos> paths[25];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool solve_word(int word_idx, int char_idx, int r, int c);

bool solve_start(int word_idx) {
    if (word_idx == N) {
        return true;
    }
    
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < L; ++j) {
            if (!used[i][j] && grid[i][j] == words[word_idx][0]) {
                used[i][j] = true;
                paths[word_idx].push_back({i + 1, j + 1});
                if (solve_word(word_idx, 1, i, j)) return true;
                paths[word_idx].pop_back();
                used[i][j] = false;
            }
        }
    }
    return false;
}

bool solve_word(int word_idx, int char_idx, int r, int c) {
    if (char_idx == (int)words[word_idx].size()) {
        return solve_start(word_idx + 1);
    }

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < A && nc >= 0 && nc < L && !used[nr][nc] && grid[nr][nc] == words[word_idx][char_idx]) {
            used[nr][nc] = true;
            paths[word_idx].push_back({nr + 1, nc + 1});
            if (solve_word(word_idx, char_idx + 1, nr, nc)) return true;
            paths[word_idx].pop_back();
            used[nr][nc] = false;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool first_case = true;
    while (cin >> N >> A >> L && (N != 0 || A != 0 || L != 0)) {
        if (!first_case) {
            cout << "\n";
        }
        first_case = false;

        for (int i = 0; i < N; ++i) {
            cin >> words[i];
            paths[i].clear();
        }
        for (int i = 0; i < A; ++i) {
            cin >> grid[i];
            for (int j = 0; j < L; ++j) {
                used[i][j] = false;
            }
        }

        solve_start(0);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < (int)paths[i].size(); ++j) {
                cout << paths[i][j].r << paths[i][j].l << (j == (int)paths[i].size() - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}