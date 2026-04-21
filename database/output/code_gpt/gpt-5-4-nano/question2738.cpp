/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C, D;
    if (!(cin >> A >> B >> C >> D)) return 0;

    array<long long,4> a = {A,B,C,D};
    array<long long,4> sorted = a;
    sort(sorted.begin(), sorted.end());

    do {
        if (a == sorted) break;
    } while (next_permutation(a.begin(), a.end()));

    int inv = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (a[i] > a[j]) inv++;
        }
    }

    vector<int> pos(4);
    array<long long,4> orig = {A,B,C,D};
    for (int i = 0; i < 4; i++) {
        long long x = orig[i];
        int cnt = 0;
        for (int j = 0; j < i; j++) if (orig[j] == x) cnt++;
        int k = -1;
        int usedBefore = 0;
        for (int j = 0; j < 4; j++) {
            if (sorted[j] == x) {
                if (usedBefore == cnt) { k = j; break; }
                usedBefore++;
            }
        }
        pos[i] = k;
    }

    int minMoves = 0;
    vector<bool> vis(4,false);
    for (int i = 0; i < 4; i++) {
        if (vis[i]) continue;
        int j = i, len = 0;
        while (!vis[j]) {
            vis[j] = true;
            j = pos[j];
            len++;
        }
        if (len > 0) minMoves += len - 1;
    }

    for (int i = 0; i < 4; i++) {
        if (i) cout << ' ';
        cout << sorted[i];
    }
    cout << "\n" << minMoves << "\n";
    return 0;
}