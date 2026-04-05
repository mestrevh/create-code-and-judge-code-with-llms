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
    long long N;
    if (!(cin >> L >> C >> N)) return 0;

    vector<vector<long long>> a(L, vector<long long>(C));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) cin >> a[i][j];
    }

    int r = (int)((N % 4 + 4) % 4);

    if (r == 0) {
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < C; j++) {
                if (j) cout << ' ';
                cout << a[i][j];
            }
            cout << '\n';
        }
        return 0;
    }

    int outL, outC;
    if (r == 1 || r == 3) {
        outL = C;
        outC = L;
    } else {
        outL = L;
        outC = C;
    }

    vector<vector<long long>> b(outL, vector<long long>(outC));

    if (r == 1) {
        for (int i = 0; i < L; i++)
            for (int j = 0; j < C; j++)
                b[j][outC - 1 - i] = a[i][j];
    } else if (r == 2) {
        for (int i = 0; i < L; i++)
            for (int j = 0; j < C; j++)
                b[outL - 1 - i][outC - 1 - j] = a[i][j];
    } else {
        for (int i = 0; i < L; i++)
            for (int j = 0; j < C; j++)
                b[outL - 1 - j][i] = a[i][j];
    }

    for (int i = 0; i < outL; i++) {
        for (int j = 0; j < outC; j++) {
            if (j) cout << ' ';
            cout << b[i][j];
        }
        cout << '\n';
    }
    return 0;
}