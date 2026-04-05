/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;

    if (n <= 1) {
        cout << 0;
        return 0;
    }

    long long N = n;
    __int128 sum = (__int128)N * (N - 1) * (N * N - N + 1) / 2;
    long long ans = (long long)sum;
    cout << ans;
    return 0;
}