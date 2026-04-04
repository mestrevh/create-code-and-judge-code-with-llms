/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int fixed_r, fixed_c;
int sol_count;
int rows[9];
bool row_used[9], d1[20], d2[20];

void backtrack(int col) {
    if (col == 9) {
        sol_count++;
        cout << setw(2) << sol_count << "      ";
        for (int i = 1; i <= 8; ++i) {
            cout << rows[i] << (i == 8 ? "" : " ");
        }
        cout << "\n";
        return;
    }

    if (col == fixed_c) {
        if (!row_used[fixed_r] && !d1[fixed_r + col] && !d2[fixed_r - col + 8]) {
            rows[col] = fixed_r;
            row_used[fixed_r] = d1[fixed_r + col] = d2[fixed_r - col + 8] = true;
            backtrack(col + 1);
            row_used[fixed_r] = d1[fixed_r + col] = d2[fixed_r - col + 8] = false;
        }
    } else {
        for (int r = 1; r <= 8; ++r) {
            if (!row_used[r] && !d1[r + col] && !d2[r - col + 8]) {
                rows[col] = r;
                row_used[r] = d1[r + col] = d2[r - col + 8] = true;
                backtrack(col + 1);
                row_used[r] = d1[r + col] = d2[r - col + 8] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    bool first_case = true;
    while (t--) {
        if (!(cin >> fixed_r >> fixed_c)) break;

        if (!first_case) cout << "\n";
        first_case = false;

        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";

        sol_count = 0;
        for (int i = 1; i <= 8; i++) row_used[i] = false;
        for (int i = 0; i < 20; i++) d1[i] = d2[i] = false;

        backtrack(1);
    }

    return 0;
}