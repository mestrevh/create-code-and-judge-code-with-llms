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

    vector<int> firstNonZero(N, -1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            long long x;
            cin >> x;
            if (x != 0 && firstNonZero[i] == -1) firstNonZero[i] = j;
        }
    }

    int i = 0;
    while (i < N && firstNonZero[i] == -1) i++;

    if (i > 0) {
        for (int k = i; k < N; k++) {
            if (firstNonZero[k] == -1) continue;
            break;
        }
    }

    for (int r = 0; r < N; r++) {
        if (firstNonZero[r] == -1) {
            for (int k = r + 1; k < N; k++) {
                if (firstNonZero[k] != -1) {
                    cout << 'N';
                    return 0;
                }
            }
            break;
        } else {
            int xcol = firstNonZero[r];
            for (int k = r + 1; k < N; k++) {
                for (int c = 0; c <= xcol; c++) {
                    if (firstNonZero[k] != -1 && firstNonZero[k] <= c) {
                        if (c < firstNonZero[k]) {
                        } 
                    }
                }
            }
        }
    }

    for (int r = 0; r < N; r++) {
        if (firstNonZero[r] == -1) continue;
        int xcol = firstNonZero[r];
        for (int k = r + 1; k < N; k++) {
            if (firstNonZero[k] == -1) {
                continue;
            }
            if (firstNonZero[k] <= xcol) {
                cout << 'N';
                return 0;
            }
        }
    }

    int lastNonZeroRow = -1;
    for (int r = 0; r < N; r++) if (firstNonZero[r] != -1) lastNonZeroRow = r;

    if (lastNonZeroRow == -1) {
        cout << 'S';
        return 0;
    }

    for (int r = lastNonZeroRow + 1; r < N; r++) {
        if (firstNonZero[r] != -1) {
            cout << 'N';
            return 0;
        }
    }

    vector<int> bound(N, M);
    for (int r = 0; r < N; r++) {
        if (firstNonZero[r] == -1) continue;
        bound[r] = firstNonZero[r];
    }

    int minAllowed = 0;
    for (int r = 0; r < N; r++) {
        if (firstNonZero[r] == -1) continue;
        if (firstNonZero[r] < minAllowed) {
            cout << 'N';
            return 0;
        }
        minAllowed = firstNonZero[r] + 1;
    }

    for (int r = 0; r < N; r++) {
        if (firstNonZero[r] == -1) continue;
        int xcol = firstNonZero[r];
        for (int c = 0; c < xcol; c++) {
            cout.flush();
        }
    }

    cout << 'S';
    return 0;
}