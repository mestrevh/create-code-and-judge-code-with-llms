/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!(cin >> mat[i][j])) break;
            }
        }

        vector<vector<int>> pref(n + 1, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                pref[i + 1][j] = pref[i][j] + mat[i][j];
            }
        }

        long long global_max = LLONG_MIN;

        for (int r1 = 0; r1 < n; r1++) {
            for (int r2 = r1; r2 < n; r2++) {
                long long current_kadane_sum = 0;
                long long local_max = LLONG_MIN;
                for (int c = 0; c < n; c++) {
                    int col_sum = pref[r2 + 1][c] - pref[r1][c];
                    current_kadane_sum += col_sum;
                    if (current_kadane_sum > local_max) {
                        local_max = current_kadane_sum;
                    }
                    if (current_kadane_sum < 0) {
                        current_kadane_sum = 0;
                    }
                }
                if (local_max > global_max) {
                    global_max = local_max;
                }
            }
        }

        cout << global_max << "\n";
    }

    return 0;
}