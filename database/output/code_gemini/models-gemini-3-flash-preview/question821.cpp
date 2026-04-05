/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int L, C;
int pref[205][205];
int col_count = 0;

void output_char(char c) {
    if (col_count == 50) {
        cout << "\n";
        col_count = 0;
    }
    cout << c;
    col_count++;
}

int get_sum(int r1, int c1, int r2, int c2) {
    return pref[r2][c2] - pref[r1 - 1][c2] - pref[r2][c1 - 1] + pref[r1 - 1][c1 - 1];
}

void decompose(int r1, int c1, int r2, int c2) {
    if (r1 > r2 || c1 > c2) return;

    int total_cells = (r2 - r1 + 1) * (c2 - c1 + 1);
    int ones = get_sum(r1, c1, r2, c2);

    if (ones == total_cells) {
        output_char('1');
    } else if (ones == 0) {
        output_char('0');
    } else {
        output_char('D');
        int rows = r2 - r1 + 1;
        int cols = c2 - c1 + 1;
        int mid_r = r1 + (rows + 1) / 2 - 1;
        int mid_c = c1 + (cols + 1) / 2 - 1;

        decompose(r1, c1, mid_r, mid_c);          // TL
        decompose(r1, mid_c + 1, mid_r, c2);      // TR
        decompose(mid_r + 1, c1, r2, mid_c);      // BL
        decompose(mid_r + 1, mid_c + 1, r2, c2);  // BR
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        if (!(cin >> L >> C)) break;

        for (int i = 1; i <= L; ++i) {
            string row_str;
            cin >> row_str;
            for (int j = 1; j <= C; ++j) {
                pref[i][j] = (row_str[j - 1] - '0') + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }

        col_count = 0;
        decompose(1, 1, L, C);
        if (col_count > 0) cout << "\n";
    }

    return 0;
}

