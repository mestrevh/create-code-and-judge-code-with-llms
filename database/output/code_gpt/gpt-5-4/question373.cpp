/*
Código criado pelo gpt-5.4
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a[4];
    for (int i = 0; i < 4; i++) cin >> a[i];

    int p[4] = {0, 1, 2, 3};
    bool ok = false;

    do {
        long long x = a[p[0]], y = a[p[1]], z = a[p[2]], w = a[p[3]];
        if (x * w == y * z) {
            ok = true;
            break;
        }
    } while (next_permutation(p, p + 4));

    cout << (ok ? 'S' : 'N') << '\n';
    return 0;
}