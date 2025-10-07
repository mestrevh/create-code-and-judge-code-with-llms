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

const int GRID_SIZE = 200;
vector<string> grid(GRID_SIZE, string(GRID_SIZE, ' '));
int min_x = GRID_SIZE, max_x = -1, min_y = GRID_SIZE, max_y = -1;

void update_bounds(int x, int y) {
    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE) return;
    min_x = min(min_x, x);
    max_x = max(max_x, x);
    min_y = min(min_y, y);
    max_y = max(max_y, y);
}

void draw_char(int x, int y, char c) {
    if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
        grid[y][x] = c;
        update_bounds(x, y);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<char, int>> commands;
    char c;
    int v;
    while (cin >> c && c != 'x') {
        cin >> v;
        commands.push_back({c, v});
    }

    if (commands.size() >= 2) {
        swap(commands[0], commands[1]);
    }

    int px = GRID_SIZE / 2;
    int py = 0;
    int f_count = 0;

    for (const auto& p : commands) {
        char cmd = p.first;
        int val = p.second;

        if (cmd == 'f') {
            f_count++;
            if (f_count == 1) { // Right
                for (int i = 0; i < val; ++i) {
                    draw_char(px, py, '-');
                    draw_char(px + 1, py, '>');
                    px += 2;
                }
                py++;
            } else { // Down
                int current_x = px;
                for (int i = 0; i < val; ++i) {
                    draw_char(current_x, py, '|');
                    py++;
                }
            }
        } else if (cmd == 'd') { // Down
            int current_x = px - 1;
            for (int i = 0; i < val; ++i) {
                draw_char(current_x, py, '|');
                py++;
            }
        } else if (cmd == 'e') { // Left
            px = px - 1;
            for (int i = 0; i < val; ++i) {
                px -= 2;
                draw_char(px, py, '<');
                draw_char(px + 1, py, '-');
            }
            py++;
        }
    }

    draw_char(px, py, 'x');

    for (int i = min_y; i <= max_y; ++i) {
        for (int j = min_x; j <= max_x; ++j) {
            if (grid[i][j] == ' ') {
                cout << '.';
            } else {
                cout << grid[i][j];
            }
        }
        cout << "\n";
    }

    return 0;
}
