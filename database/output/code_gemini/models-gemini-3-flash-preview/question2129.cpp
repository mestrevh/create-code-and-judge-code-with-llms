/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int M, N;
int grid[1005][1005];
bool visited[1005][1005];
vector<string> path;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
string dnames[] = {"Sul", "Leste", "Norte", "Oeste"};

bool solve(int r, int c) {
    if (r == M - 1 && c == N - 1) return true;
    
    visited[r][c] = true;
    
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if (nr >= 0 && nr < M && nc >= 0 && nc < N && grid[nr][nc] == 1 && !visited[nr][nc]) {
            path.push_back(dnames[i]);
            if (solve(nr, nc)) return true;
            path.pop_back();
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> M >> N)) return 0;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    if (M <= 0 || N <= 0) return 0;

    if (grid[0][0] == 1 && solve(0, 0)) {
        if (path.empty()) {
            if (M == 1 && N == 1) {
                // If the start is the exit and no moves are made, output nothing or specific string.
                // Based on standard ICPC practices, a blank line or empty string is typical.
            }
        } else {
            string result = "";
            int count = 1;
            for (size_t i = 1; i < path.size(); ++i) {
                if (path[i] == path[i - 1]) {
                    count++;
                } else {
                    result += to_string(count) + "*" + path[i - 1] + ", ";
                    count = 1;
                }
            }
            result += to_string(count) + "*" + path.back();
            cout << result << endl;
        }
    } else {
        cout << "Welcome to the Upside Down." << endl;
    }

    return 0;
}