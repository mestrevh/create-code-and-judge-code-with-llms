/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int caseNum = 0;
    while (cin >> n) {
        char s;
        if (!(cin >> s)) break;

        vector<vector<char>> board(n, vector<char>(n, '.'));
        string line;
        getline(cin, line); // consume the rest of the line with starting player 's'

        int moveCount = 0;
        // Read moves for the current case until a blank line is reached.
        while (getline(cin, line)) {
            bool hasDigits = false;
            for (char ch : line) {
                if (isdigit(ch)) {
                    hasDigits = true;
                    break;
                }
            }
            if (!hasDigits) {
                if (moveCount > 0) break; // End of moves for this case
                else continue; // Skip lines before moves start
            }
            stringstream ss(line);
            int r, c;
            while (ss >> r >> c) {
                char cur = (moveCount % 2 == 0) ? s : (s == 'B' ? 'W' : 'B');
                if (r >= 0 && r < n && c >= 0 && c < n) {
                    board[r][c] = cur;
                }
                moveCount++;
            }
        }

        char winner = ' ';
        int area = 0;
        int dr[] = {-1, -1, 0, 0, 1, 1};
        int dc[] = {0, 1, -1, 1, -1, 0};

        // Check Winner W: Needs a path from Row 0 to Row N-1.
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'W' && !visited[0][j]) {
                queue<pair<int, int>> q;
                q.push({0, j});
                visited[0][j] = true;
                int currentArea = 0;
                bool reachesBottom = false;
                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    currentArea++;
                    if (cur.first == n - 1) reachesBottom = true;
                    for (int k = 0; k < 6; ++k) {
                        int nr = cur.first + dr[k];
                        int nc = cur.second + dc[k];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] == 'W' && !visited[nr][nc]) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
                if (reachesBottom) {
                    winner = 'W';
                    area = currentArea;
                    break;
                }
            }
        }

        // Check Winner B: Needs a path from Column 0 to Column N-1.
        if (winner == ' ') {
            visited.assign(n, vector<bool>(n, false));
            for (int i = 0; i < n; ++i) {
                if (board[i][0] == 'B' && !visited[i][0]) {
                    queue<pair<int, int>> q;
                    q.push({i, 0});
                    visited[i][0] = true;
                    int currentArea = 0;
                    bool reachesRight = false;
                    while (!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();
                        currentArea++;
                        if (cur.second == n - 1) reachesRight = true;
                        for (int k = 0; k < 6; ++k) {
                            int nr = cur.first + dr[k];
                            int nc = cur.second + dc[k];
                            if (nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] == 'B' && !visited[nr][nc]) {
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                    if (reachesRight) {
                        winner = 'B';
                        area = currentArea;
                        break;
                    }
                }
            }
        }

        cout << "caso " << caseNum++ << ": " << winner << " " << area << "\n\n";
    }

    return 0;
}