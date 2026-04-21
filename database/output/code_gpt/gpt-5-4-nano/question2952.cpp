/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    if (!(cin >> K)) return 0;
    int N, M;
    cin >> N >> M;

    vector<string> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    int totalEmpty = 0;
    for (int i = 0; i < N; i++)
        for (char c : a[i])
            if (c == 'o') totalEmpty++;

    auto findBlock = [&](int len) -> tuple<int,int,int> {
        for (int i = 0; i < N; i++) {
            int bestStart = -1;
            for (int j = 0; j + len <= M; j++) {
                bool ok = true;
                for (int t = 0; t < len; t++) {
                    if (a[i][j + t] != 'o') { ok = false; break; }
                }
                if (ok) bestStart = j;
            }
            if (bestStart != -1) return {i, bestStart, len};
        }
        return {-1,-1,-1};
    };

    if (K > M) {
        if (totalEmpty < K) {
            cout << K - totalEmpty << " sentados, " << totalEmpty - (totalEmpty) << " em pé";
            return 0;
        }
    }

    auto [bi, bs, bl] = findBlock(K);
    if (bi != -1) {
        cout << "Todos sentados e juntos\n";
        for (int t = 0; t < K; t++) a[bi][bs + t] = '*';
        for (int i = 0; i < N; i++) cout << a[i] << "\n";
        return 0;
    }

    if (totalEmpty >= K) {
        cout << "Todos sentados, mas separados\n";
        int placed = 0;
        for (int i = 0; i < N && placed < K; i++) {
            for (int j = M - 1; j >= 0 && placed < K; j--) {
                if (a[i][j] == 'o') {
                    a[i][j] = '*';
                    placed++;
                }
            }
        }
        for (int i = 0; i < N; i++) cout << a[i] << "\n";
        return 0;
    }

    int X = totalEmpty;
    cout << X << " sentados, " << (K - X) << " em pé\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 'o') a[i][j] = '*';
        }
    }
    for (int i = 0; i < N; i++) cout << a[i] << "\n";
    return 0;
}