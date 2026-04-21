/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char cmd;
    int r = 0;
    int c = 20;
    map<int, map<int, char>> grid;
    bool after_f = false;
    bool last_was_d = true;

    while (cin >> cmd && cmd != 'x') {
        if (cmd == 'd') {
            int n;
            if (!(cin >> n)) break;
            if (after_f) r++;
            for (int i = 0; i < n; i++) {
                c++;
                grid[r][c] = '-';
                c++;
                grid[r][c] = '>';
            }
            last_was_d = true;
            after_f = false;
        } else if (cmd == 'e') {
            int n;
            if (!(cin >> n)) break;
            if (after_f) r++;
            for (int i = 0; i < n; i++) {
                c--;
                grid[r][c] = '-';
                c--;
                grid[r][c] = '<';
            }
            last_was_d = false;
            after_f = false;
        } else if (cmd == 'f') {
            int n;
            if (!(cin >> n)) break;
            int char_c = last_was_d ? c + 1 : c;
            for (int i = 0; i < n; i++) {
                r++;
                grid[r][char_c] = '|';
            }
            c = char_c;
            after_f = true;
        } else if (cmd == 't') {
            int n;
            if (!(cin >> n)) break;
            int char_c = last_was_d ? c + 1 : c;
            for (int i = 0; i < n; i++) {
                r--;
                grid[r][char_c] = '|';
            }
            c = char_c;
            after_f = true;
        }
    }

    int final_c = last_was_d ? c + 1 : c;
    r++;
    grid[r][final_c] = 'x';

    if (grid.empty()) return 0;

    int min_r = 2147483647, max_r = -2147483648, global_min_c = 2147483647;
    for (auto const& row_entry : grid) {
        int ri = row_entry.first;
        min_r = min(min_r, ri);
        max_r = max(max_r, ri);
        for (auto const& col_entry : row_entry.second) {
            global_min_c = min(global_min_c, col_entry.first);
        }
    }

    int shift_c = (global_min_c < 1) ? 1 - global_min_c : 0;

    for (int i = min_r; i <= max_r; i++) {
        cout << ".";
        if (grid.count(i)) {
            int max_c_in_row = -2147483648;
            for (auto const& col_entry : grid[i]) {
                max_c_in_row = max(max_c_in_row, col_entry.first + shift_c);
            }
            for (int j = 1; j <= max_c_in_row; j++) {
                int original_c = j - shift_c;
                if (grid[i].count(original_c)) {
                    cout << grid[i][original_c];
                } else {
                    cout << " ";
                }
            }
        }
        cout << "\n";
    }

    return 0;
}