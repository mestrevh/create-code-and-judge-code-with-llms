/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P;
    int N;
    if (!(cin >> P >> N)) return 0;

    vector<int> cnt(P + 1, 0);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x < 1 || x > P) continue;
        cnt[x]++;
    }

    long long totalPairs = 0;
    for (int i = 1; i <= P; i++) {
        int next = (i == P) ? 1 : i + 1;
        totalPairs += 1LL * cnt[i] * cnt[next];
    }

    cout << (totalPairs == 0 ? "S" : "N");
    return 0;
}