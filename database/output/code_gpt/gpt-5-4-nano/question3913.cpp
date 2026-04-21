/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a[4], e[4], r[4];
    if (!(cin >> a[0] >> a[1] >> a[2] >> a[3])) return 0;
    cin >> e[0] >> e[1] >> e[2] >> e[3];
    cin >> r[0] >> r[1] >> r[2] >> r[3];

    for (int i = 0; i < 4; i++) e[i] += r[i];

    int allyWins = 0, enemyWins = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] > e[i]) allyWins++;
        if (e[i] > a[i]) enemyWins++;
    }

    if (allyWins > 2) cout << "Avancar";
    else if (enemyWins > 2) cout << "Recuar";
    else cout << "Permanecer";

    return 0;
}