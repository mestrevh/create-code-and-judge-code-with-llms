/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, C;
    if (!(cin >> L >> C)) return 0;

    int N = L * C;
    vector<int> grid(N, 0);
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            string s;
            cin >> s;
            int val = 0;
            if (s == "verde") val = 0;
            else if (s == "amarelo") val = 1;
            else val = 2; 
            grid[i * C + j] = val;
        }
    }

    int S;
    cin >> S;

    long long expensive = 0;
    long long countExcellentAfter = 0;

    for (int i = 0; i < S; i++) {
        int X, Y;
        cin >> X >> Y;
        --X; --Y;
        int idx = X * C + Y;
        int before = grid[idx];
        if (before == 0) continue;
        grid[idx] = 0;
    }

    for (int i = 0; i < N; i++) {
        if (grid[i] == 0) countExcellentAfter++;
    }

    for (int i = 0; i < N; i++) {
        if (grid[i] == 0) continue;
    }

    for (int i = 0; i < N; i++) {
        if (grid[i] == 2) expensive++;
    }

    for (int i = 0; i < N; i++) {
        if (grid[i] == 1 || grid[i] == 2) {
            if (grid[i] == 2) {}
        }
    }

    for (int i = 0; i < N; i++) {
        if (grid[i] == 2) {}
    }

    long long profit = countExcellentAfter * 4 - expensive * 3;
    if (profit < 0) {
        cout << "prejuizo";
    } else {
        cout << profit;
    }
    return 0;
}