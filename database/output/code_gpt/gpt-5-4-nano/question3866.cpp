/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<vector<long long>> a(N, vector<long long>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    int maxCols = 0;
    for (int i = 0; i < N; i++) maxCols = max(maxCols, M);

    const long long LIM = (long long)4e18;

    for (int col = 0; col < M; col++) {
        bool hasKnown = false;
        long long r = 1;

        for (int i = 0; i < N; i++) {
            if (a[i][col] != -1) {
                hasKnown = true;
                if (i + 1 < N && a[i + 1][col] != -1) {
                    long long x = a[i][col], y = a[i + 1][col];
                    if (x != 0) {
                        if (y % x == 0) r = y / x;
                    }
                }
                break;
            }
        }

        if (!hasKnown) continue;

        bool rKnown = false;
        for (int i = 0; i + 1 < N; i++) {
            if (a[i][col] != -1 && a[i + 1][col] != -1) {
                long long x = a[i][col], y = a[i + 1][col];
                if (x == 0) {
                    r = (y == 0 ? 1 : 0);
                    rKnown = true;
                    break;
                }
                if (y % x == 0) {
                    r = y / x;
                } else {
                    r = 1;
                }
                rKnown = true;
                break;
            }
        }

        if (!rKnown) {
            long long first = -1;
            for (int i = 0; i < N; i++) if (a[i][col] != -1) { first = a[i][col]; break; }
            if (first == -1) continue;
            r = 1;
        }

        auto safeMul = [&](long long p, long long q) -> long long {
            if (p == 0 || q == 0) return 0;
            __int128 t = (__int128)p * (__int128)q;
            if (t > LIM || t < -LIM) return (t > 0 ? LIM : -LIM);
            return (long long)t;
        };

        for (int i = 0; i < N; i++) {
            if (a[i][col] != -1) {
                if (i > 0 && a[i-1][col] == -1) {
                    long long prev = a[i][col];
                    bool divides = (r != 0 && prev % r == 0);
                    if (r == 0) {
                        a[i-1][col] = 0;
                    } else if (divides) {
                        a[i-1][col] = prev / r;
                    } else {
                        a[i-1][col] = prev;
                    }
                }
                if (i + 1 < N && a[i+1][col] == -1) {
                    long long next = safeMul(a[i][col], r);
                    a[i+1][col] = next;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (a[i][col] == -1) {
                int left = i-1;
                while (left >= 0 && a[left][col] == -1) left--;
                if (left >= 0) {
                    long long val = a[left][col];
                    for (int k = left + 1; k <= i; k++) val = safeMul(val, r);
                    a[i][col] = val;
                } else {
                    int right = i+1;
                    while (right < N && a[right][col] == -1) right++;
                    if (right < N) {
                        long long val = a[right][col];
                        for (int k = right - 1; k >= i; k--) {
                            if (r != 0 && val % r == 0) val /= r;
                            else val = val;
                        }
                        a[i][col] = val;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << ' ';
            cout << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}