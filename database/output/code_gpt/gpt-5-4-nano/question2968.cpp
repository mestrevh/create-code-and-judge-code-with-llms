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

    vector<vector<int>> a(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> a[i][j];

    string off = "Queria que todo mundo fosse assim";
    string on = "Desliga o farol cidadao ( ._.)";

    for (int col = 0; col < M; col++) {
        if (col % 2 == 0) {
            for (int row = 0; row < N; row++) {
                cout << (a[row][col] == 1 ? on : off) << "\n";
            }
        } else {
            for (int row = N - 1; row >= 0; row--) {
                cout << (a[row][col] == 1 ? on : off) << "\n";
            }
        }
    }

    return 0;
}