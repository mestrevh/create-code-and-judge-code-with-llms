/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <limits>

const int dr[] = {-1, -1, 0, 0, 1, 1};
const int dc[] = {0, 1, -1, 1, 0, -1};

bool is_valid(int r, int c, int N) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

int find_winning_component_size(char player, int N, const std::vector<std::vector<char>>& board) {
    std::vector<std::vector<bool>> from_start(N, std::vector<bool>(N, false));
    std::vector<std::vector<bool>> from_end(N, std::vector<bool>(N, false));
    std::queue<std::pair<int, int>> q;

    if (player == 'W') {
        for (int c = 0; c < N; ++c) {
            if (board[0][c] == 'W') {
                if (!from_start[0][c]) {
                    q.push({0, c});
                    from_start[0][c] = true;
                }
            }
        }
    } else {
        for (int r = 0; r < N; ++r) {
            if (board[r][0] == 'B') {
                if (!from_start[r][0]) {
                    q.push({r, 0});
                    from_start[r][0] = true;
                }
            }
        }
    }

    while (!q.empty()) {
        std::pair<int, int> curr = q.front();
        q.pop();
        int r = curr.first;
        int c = curr.second;
        for (int i = 0; i < 6; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (is_valid(nr, nc, N) && board[nr][nc] == player && !from_start[nr][nc]) {
                from_start[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    if (player == 'W') {
        for (int c = 0; c < N; ++c) {
            if (board[N - 1][c] == 'W') {
                if (!from_end[N-1][c]) {
                    q.push({N - 1, c});
                    from_end[N - 1][c] = true;
                }
            }
        }
    } else {
        for (int r = 0; r < N; ++r) {
            if (board[r][N - 1] == 'B') {
                 if (!from_end[r][N-1]) {
                    q.push({r, N - 1});
                    from_end[r][N - 1] = true;
                }
            }
        }
    }

    while (!q.empty()) {
        std::pair<int, int> curr = q.front();
        q.pop();
        int r = curr.first;
        int c = curr.second;
        for (int i = 0; i < 6; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (is_valid(nr, nc, N) && board[nr][nc] == player && !from_end[nr][nc]) {
                from_end[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    
    int area_count = 0;
    bool path_exists = false;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (from_start[i][j] && from_end[i][j]) {
                path_exists = true;
                area_count++;
            }
        }
    }
    
    return path_exists ? area_count : 0;
}

void solve() {
    int N;
    int case_num = 0;
    while (std::cin >> N) {
        char start_player;
        std::cin >> start_player;

        std::vector<std::vector<char>> board(N, std::vector<char>(N, '.'));
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::string line;
        char current_player = start_player;
        while (std::getline(std::cin, line) && !line.empty()) {
            std::stringstream ss(line);
            int r, c;
            if (ss >> r >> c) {
                board[r][c] = current_player;
                current_player = (current_player == 'B') ? 'W' : 'B';
            }
        }

        int area_b = find_winning_component_size('B', N, board);
        if (area_b > 0) {
            std::cout << "caso " << case_num++ << ": B " << area_b << "\n\n";
        } else {
            int area_w = find_winning_component_size('W', N, board);
            std::cout << "caso " << case_num++ << ": W " << area_w << "\n\n";
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
