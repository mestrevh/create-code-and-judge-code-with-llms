/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<vector<long long>> A(N, vector<long long>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    vector<vector<long long>> B(N, vector<long long>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> B[i][j];

    vector<vector<long long>> C(N, vector<long long>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            long long aik = A[i][k];
            for (int j = 0; j < N; j++) {
                C[i][j] += aik * B[k][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j) cout << ' ';
            cout << C[i][j];
        }
        cout << "\n";
    }

    bool ok = true;
    for (int i = 0; i < N && ok; i++) {
        for (int j = 0; j < N; j++) {
            long long expected = (i == j) ? 1 : 0;
            if (C[i][j] != expected) {
                ok = false;
                break;
            }
        }
    }

    cout << (ok ? "Acertou" : "Errou");
    return 0;
}