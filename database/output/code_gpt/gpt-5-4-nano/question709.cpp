/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, o;
    if (!(cin >> n >> m >> o)) return 0;

    vector<long long> board(n);
    for (int i = 0; i < n; i++) cin >> board[i];

    int totalMoves = o * m;
    vector<int> dice(totalMoves);
    for (int i = 0; i < totalMoves; i++) cin >> dice[i];

    vector<int> pos(m, 0);

    auto mod = [&](long long x) -> int {
        long long r = x % n;
        if (r < 0) r += n;
        return (int)r;
    };

    int idx = 0;
    for (int round = 0; round < o; round++) {
        for (int player = 0; player < m; player++) {
            int v = dice[idx++];
            long long p1 = (long long)pos[player] + v;
            pos[player] = mod(p1);
            long long x = board[pos[player]];
            if (x != 0) pos[player] = mod((long long)pos[player] + x);
        }
    }

    for (int i = 0; i < m; i++) {
        cout << pos[i] << "\n";
    }
    return 0;
}