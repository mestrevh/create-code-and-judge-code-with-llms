/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> freq(10, 0);
    int ignored = 0;
    for (int i = 0; i < N; ++i) {
        double x;
        if (!(cin >> x)) break;
        if (x >= 0.0 && x <= 1.0) freq[0]++;
        else if (x > 1.0 && x <= 2.0) freq[1]++;
        else if (x > 2.0 && x <= 3.0) freq[2]++;
        else if (x > 3.0 && x <= 4.0) freq[3]++;
        else if (x > 4.0 && x <= 5.0) freq[4]++;
        else if (x > 5.0 && x <= 6.0) freq[5]++;
        else if (x > 6.0 && x <= 7.0) freq[6]++;
        else if (x > 7.0 && x <= 8.0) freq[7]++;
        else if (x > 8.0 && x <= 9.0) freq[8]++;
        else if (x > 9.0 && x <= 10.0) freq[9]++;
        else ignored++;
    }

    int max_freq = 0;
    for (int i = 0; i < 10; ++i) if (freq[i] > max_freq) max_freq = freq[i];

    vector<int> H(10, 0);
    if (max_freq > 0) {
        for (int i = 0; i < 10; ++i) {
            H[i] = (int)((long long)freq[i] * 20 / max_freq);
        }
    }

    vector<string> grid(23, string(35, ' '));
    grid[22][5] = '^';
    for (int r = 1; r <= 21; ++r) grid[r][5] = '|';

    set<int> L_set;
    L_set.insert(0);
    if (max_freq > 0) {
        L_set.insert(max_freq);
        L_set.insert(max_freq / 4);
        L_set.insert(2 * max_freq / 4);
        L_set.insert(3 * max_freq / 4);
    }

    for (int L : L_set) {
        int r = (max_freq > 0) ? (int)((long long)L * 20 / max_freq) : 0;
        grid[r][5] = '+';
        string s = to_string(L);
        for (int i = 0; i < (int)s.length(); ++i) {
            grid[r][3 - ((int)s.length() - 1 - i)] = s[i];
        }
    }

    for (int i = 0; i < 10; ++i) {
        int col_star = 2 * i + 6;
        for (int r = 1; r <= H[i]; ++r) grid[r][col_star] = '*';
        grid[H[i] + 1][col_star] = '_';
    }

    for (int i = 0; i <= 10; ++i) {
        int col_sep = 2 * i + 5;
        int h_left = (i > 0) ? H[i - 1] : 0;
        int h_right = (i < 10) ? H[i] : 0;
        int h_max = max(h_left, h_right);
        for (int r = 1; r <= h_max; ++r) {
            if (grid[r][col_sep] == ' ') grid[r][col_sep] = '|';
        }
    }

    for (int c = 6; c <= 13; ++c) grid[0][c] = '-';
    for (int c = 15; c <= 23; ++c) grid[0][c] = '-';
    grid[0][5] = '+'; grid[0][14] = '+'; grid[0][24] = '+';
    grid[0][25] = '-'; grid[0][26] = '>';

    for (int r = 22; r >= 0; --r) {
        string row = grid[r];
        while (!row.empty() && row.back() == ' ') row.pop_back();
        if (!row.empty()) {
            cout << row << endl;
        } else if (r > 0) {
            // Check if there are any axis elements to print
            bool axis_element = false;
            for(int c=0; c<6; ++c) if(grid[r][c] != ' ') axis_element = true;
            if(axis_element) {
                while (!row.empty() && row.back() == ' ') row.pop_back();
                cout << row << endl;
            } else {
                // Just the axis pipe
                cout << "     |" << endl;
            }
        }
    }

    cout << "    0.0      5.0      10.0" << endl;
    cout << "Valores ignorados: " << ignored << endl;

    return 0;
}