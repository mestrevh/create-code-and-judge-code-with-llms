/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

bool visited[35][85];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void solve(std::vector<std::string>& grid) {
    if (grid.empty()) {
        return;
    }
    int rows = grid.size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < 85; ++j) {
            visited[i][j] = false;
        }
    }

    char contour_char = 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < grid[r].length(); ++c) {
            if (grid[r][c] != ' ') {
                contour_char = grid[r][c];
                goto contour_found;
            }
        }
    }
contour_found:;

    if (contour_char == 0) {
        return;
    }

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < grid[r].length(); ++c) {
            if (!visited[r][c] && grid[r][c] != contour_char) {
                char mark_found = ' ';
                std::vector<std::pair<int, int>> space_coords;
                std::queue<std::pair<int, int>> q;

                q.push({r, c});
                visited[r][c] = true;

                while (!q.empty()) {
                    std::pair<int, int> curr = q.front();
                    q.pop();
                    int cr = curr.first;
                    int cc = curr.second;

                    if (grid[cr][cc] == ' ') {
                        space_coords.push_back(curr);
                    } else {
                        mark_found = grid[cr][cc];
                    }

                    for (int i = 0; i < 4; ++i) {
                        int nr = cr + dr[i];
                        int nc = cc + dc[i];

                        if (nr >= 0 && nr < rows && nc >= 0 && nc < grid[nr].length()) {
                            if (!visited[nr][nc] && grid[nr][nc] != contour_char) {
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                }

                if (mark_found != ' ') {
                    for (const auto& p : space_coords) {
                        grid[p.first][p.second] = mark_found;
                    }
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> current_grid;
    std::string line;

    while (getline(std::cin, line)) {
        bool is_separator = false;
        if (!line.empty() && line.find_first_not_of('_') == std::string::npos) {
            is_separator = true;
        }

        if (is_separator) {
            solve(current_grid);
            for (const auto& grid_line : current_grid) {
                std::cout << grid_line << "\n";
            }
            std::cout << line << "\n";
            current_grid.clear();
        } else {
            current_grid.push_back(line);
        }
    }

    return 0;
}
