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
    long long ans = 0;
    long long cur = 0;
    long long prev;
    cin >> prev;
    cur = 1;
    ans = 1;

    for (int i = 1; i < N; i++) {
        long long x;
        cin >> x;
        if (x == prev) {
            cur++;
        } else {
            prev = x;
            cur = 1;
        }
        if (cur > ans) ans = cur;
    }

    cout << ans << "\n";
    return 0;
}