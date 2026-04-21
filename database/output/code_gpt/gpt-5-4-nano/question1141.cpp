/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P;
    if (!(cin >> N >> P)) return 0;

    vector<vector<int>> grid(N, vector<int>(N, 0));
    for (int i = 0; i < P; i++) {
        int L, C;
        cin >> L >> C;
        --L; --C;
        grid[L][C] = 1;
    }
    for (int i = 0; i < P; i++) {
        int L, C;
        cin >> L >> C;
        --L; --C;
        grid[L][C] = 2;
    }

    vector<vector<int>> prefBlack(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> prefWhite(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            prefBlack[i][j] = prefBlack[i-1][j] + prefBlack[i][j-1] - prefBlack[i-1][j-1] + (grid[i-1][j-1] == 1);
            prefWhite[i][j] = prefWhite[i-1][j] + prefWhite[i][j-1] - prefWhite[i-1][j-1] + (grid[i-1][j-1] == 2);
        }
    }

    auto sumRect = [&](const vector<vector<int>>& pref, int r1, int c1, int r2, int c2) -> int {
        return pref[r2][c2] - pref[r1][c2] - pref[r2][c1] + pref[r1][c1];
    };

    long long ansBlack = 0, ansWhite = 0;
    for (int s = 1; s <= N; s++) {
        int limit = N - s + 1;
        for (int i = 0; i < limit; i++) {
            for (int j = 0; j < limit; j++) {
                int r1 = i, c1 = j, r2 = i + s, c2 = j + s;
                int b = sumRect(prefBlack, r1, c1, r2, c2);
                if (b > 0) {
                    int w = sumRect(prefWhite, r1, c1, r2, c2);
                    if (w == 0) ansBlack++;
                }
                int w = sumRect(prefWhite, r1, c1, r2, c2);
                if (w > 0) {
                    int b2 = sumRect(prefBlack, r1, c1, r2, c2);
                    if (b2 == 0) ansWhite++;
                }
            }
        }
    }

    cout << ansBlack << ' ' << ansWhite << "\n";
    return 0;
}