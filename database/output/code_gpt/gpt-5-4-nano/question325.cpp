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

    for (int i = 1; i <= N; i++) {
        long long sq = 1LL * i * i;
        long long cu = sq * i;
        cout << i << ' ' << sq << ' ' << cu;
        if (i < N) cout << "\n";
    }
    return 0;
}