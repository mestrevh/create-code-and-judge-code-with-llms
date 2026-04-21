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

    int K;
    cin >> K;

    vector<vector<long long>> mat(N, vector<long long>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> mat[i][j];

    vector<int> rowMap(N), colMap(M);
    iota(rowMap.begin(), rowMap.end(), 0);
    iota(colMap.begin(), colMap.end(), 0);

    for (int t = 0; t < K; t++) {
        string cmd;
        int A, B;
        cin >> cmd >> A >> B;
        if (cmd == "ataque") {
            if (0 <= A && A < N && 0 <= B && B < N) swap(rowMap[A], rowMap[B]);
        } else {
            if (0 <= A && A < M && 0 <= B && B < M) swap(colMap[A], colMap[B]);
        }
    }

    int I, J;
    cin >> I >> J;
    cout << mat[rowMap[I]][colMap[J]] << "\n";
    return 0;
}