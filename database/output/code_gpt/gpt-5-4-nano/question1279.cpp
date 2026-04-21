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

    if (N <= 0) {
        cout << "Vazia";
        return 0;
    }

    vector<vector<long long>> A(N, vector<long long>(N));
    vector<vector<long long>> B(N, vector<long long>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> B[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] + B[i][j];
            if (!(i == N - 1 && j == N - 1)) cout << "\n";
        }
    }
    return 0;
}