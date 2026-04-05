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

    vector<long long> t(N), k(N);
    for (int i = 0; i < N; i++) cin >> t[i];
    for (int i = 0; i < N; i++) cin >> k[i];

    long long cur = 0;
    for (int i = 0; i < N; i++) {
        long long interval = k[i];
        long long wait = 0;
        if (cur > 0) {
            wait = (interval - (cur % interval)) % interval;
        }
        cur += wait;
        cur += t[i];
    }

    cout << cur << "\n";
    return 0;
}