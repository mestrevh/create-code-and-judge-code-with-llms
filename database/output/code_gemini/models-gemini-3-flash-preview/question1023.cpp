/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(int r, int c, char fillChar, vector<string>& grid) {
    if (r < 0 || r >= (int)grid.size() || c < 0 || c >= (int)grid[r].size()) return;
    if (grid[r][c] != ' ') return;
    grid[r][c] = fillChar;
    dfs(r + 1, c, fillChar, grid);
    dfs(r - 1, c, fillChar, grid);
    dfs(r, c + 1, fillChar, grid);
    dfs(r, c - 1, fillChar, grid);
}

struct Marking {
    int r, c;
    char ch;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string line;
    vector<string> grid;
    while (getline(cin, line)) {
        if (!line.empty() && line[0] == '_') {
            char contourChar = '\0';
            bool foundContour = false;
            for (int r = 0; r < (int)grid.size(); ++r) {
                for (int c = 0; c < (int)grid[r].size(); ++c) {
                    if (grid[r][c] != ' ' && grid[r][c] != '_') {
                        contourChar = grid[r][c];
                        foundContour = true;
                        break;
                    }
                }
                if (foundContour) break;
            }
            
            if (foundContour) {
                vector<Marking> marks;
                for (int r = 0; r < (int)grid.size(); ++r) {
                    for (int c = 0; c < (int)grid[r].size(); ++c) {
                        if (grid[r][c] != ' ' && grid[r][c] != '_' && grid[r][c] != contourChar) {
                            marks.push_back({r, c, grid[r][c]});
                        }
                    }
                }
                for (const auto& m : marks) {
                    int dr[] = {1, -1, 0, 0};
                    int dc[] = {0, 0, 1, -1};
                    for (int i = 0; i < 4; ++i) {
                        dfs(m.r + dr[i], m.c + dc[i], m.ch, grid);
                    }
                }
            }
            
            for (const auto& row : grid) {
                cout << row << "\n";
            }
            cout << line << "\n";
            grid.clear();
        } else {
            grid.push_back(line);
        }
    }
    
    if (!grid.empty()) {
        char contourChar = '\0';
        bool foundContour = false;
        for (int r = 0; r < (int)grid.size(); ++r) {
            for (int c = 0; c < (int)grid[r].size(); ++c) {
                if (grid[r][c] != ' ' && grid[r][c] != '_') {
                    contourChar = grid[r][c];
                    foundContour = true;
                    break;
                }
            }
            if (foundContour) break;
        }
        if (foundContour) {
            vector<Marking> marks;
            for (int r = 0; r < (int)grid.size(); ++r) {
                for (int c = 0; c < (int)grid[r].size(); ++c) {
                    if (grid[r][c] != ' ' && grid[r][c] != '_' && grid[r][c] != contourChar) {
                        marks.push_back({r, c, grid[r][c]});
                    }
                }
            }
            for (const auto& m : marks) {
                int dr[] = {1, -1, 0, 0};
                int dc[] = {0, 0, 1, -1};
                for (int i = 0; i < 4; ++i) {
                    dfs(m.r + dr[i], m.c + dc[i], m.ch, grid);
                }
            }
        }
        for (const auto& row : grid) {
            cout << row << "\n";
        }
    }
    
    return 0;
}