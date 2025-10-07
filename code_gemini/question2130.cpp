/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int M, N;
vector<vector<int>> grid;
vector<vector<vector<int>>> min_turns_visited;
int min_total_complexity = INT_MAX;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool is_valid(int r, int c) {
    return r >= 0 && r < M && c >= 0 && c < N && grid[r][c] == 1;
}

bool is_vertical(int dir) {
    return dir == 0 || dir == 1;
}

void find_path(int r, int c, int prev_dir, int current_turns) {
    if (!is_valid(r, c)) {
        return;
    }

    if (current_turns >= min_turns_visited[r][c][prev_dir]) {
        return;
    }
    
    if (current_turns >= min_total_complexity) {
        return;
    }

    min_turns_visited[r][c][prev_dir] = current_turns;

    if (r == M - 1 && c == N - 1) {
        min_total_complexity = min(min_total_complexity, current_turns);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        
        int next_turns = current_turns;
        if (prev_dir != 4 && is_vertical(prev_dir) != is_vertical(i)) {
            next_turns++;
        }
        
        find_path(next_r, next_c, i, next_turns);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;

    grid.resize(M, vector<int>(N));
    min_turns_visited.resize(M, vector<vector<int>>(N, vector<int>(5, INT_MAX)));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    find_path(0, 0, 4, 0);

    if (min_total_complexity == INT_MAX) {
        cout << "Welcome to the Upside Down." << endl;
    } else {
        cout << "O caminho tem complexidade: " << min_total_complexity << endl;
    }

    return 0;
}
