/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    if (!(cin >> N >> D)) return 0;

    long long ans = 0;
    for (int c = 0; c <= N; c++) {
        int k = N - c;
        if (abs(c - k) == D) ans++;
    }
    cout << ans << "\n";
    return 0;
}