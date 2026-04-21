/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;
    vector<long long> a(N);
    for (long long i = 0; i < N; i++) cin >> a[i];

    long long ans = 0;
    for (long long i = 0; i < N; i++) {
        for (long long j = i + 1; j < N; j++) {
            ans += llabs(a[i] - a[j]);
        }
    }
    cout << ans << "\n";
    return 0;
}