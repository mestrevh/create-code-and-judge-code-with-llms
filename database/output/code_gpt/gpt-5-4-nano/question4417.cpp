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
    long long B;
    if (!(cin >> N >> B)) return 0;

    vector<string> board(N, string(N, '-'));

    for (int i = 0; i < N && i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            long long bitIndex = (long long)i * N + j;
            if ((B >> bitIndex) & 1LL) board[i][j] = 'x';
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << board[i] << "\n";
    }
    return 0;
}