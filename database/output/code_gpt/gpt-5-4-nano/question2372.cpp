/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, C;
    if (!(cin >> L)) return 0;
    cin >> C;

    long long cnt = 0;
    for (int i = 0; i < L * C; i++) {
        long long x;
        cin >> x;
        if (x % 2 == 0) cnt++;
    }

    cout << cnt << "\n";
    return 0;
}