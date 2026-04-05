/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, A, B;
    if (!(cin >> N)) return 0;
    cin >> M >> A >> B;

    vector<vector<long long>> X(N, vector<long long>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> X[i][j];
    }

    vector<vector<long long>> Y(A, vector<long long>(B));
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) cin >> Y[i][j];
    }

    if (M != A) {
        cout << "Nao eh possivel multiplicar!";
        return 0;
    }

    vector<vector<long long>> Z(N, vector<long long>(B, 0));
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            long long xik = X[i][k];
            for (int j = 0; j < B; j++) {
                Z[i][j] += xik * Y[k][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < B; j++) {
            if (j) cout << ' ';
            cout << Z[i][j];
        }
        if (i + 1 < N) cout << "\n";
        else cout << "\n";
    }

    return 0;
}