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
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    vector<long long> pref(N), suf(N);
    for (int i = 0; i < N; i++) {
        pref[i] = (i == 0 ? H[i] : max(pref[i - 1], H[i]));
    }
    for (int i = N - 1; i >= 0; i--) {
        suf[i] = (i == N - 1 ? H[i] : max(suf[i + 1], H[i]));
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long water = min(pref[i], suf[i]) - H[i];
        if (water >= 1) ans++;
    }

    cout << ans << "\n";
    return 0;
}