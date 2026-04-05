/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h1, m1, h2, m2, h3, m3;
    if (!(cin >> h1 >> m1 >> h2 >> m2 >> h3 >> m3)) return 0;

    auto toMinutes = [](int h, int m) { return h * 60 + m; };

    int t1 = toMinutes(h1, m1);
    int t2 = toMinutes(h2, m2);
    int t3 = toMinutes(h3, m3);

    vector<char> res(3, 'f');

    if (t1 >= 0 && t1 < 720) res[0] = 'v';

    int dt12 = (t2 - t1 + 1440) % 1440;
    if (dt12 == (3 * 60 + 12) && res[0] == 'v') res[1] = 'v';

    int dt23 = (t3 - t2 + 1440) % 1440;
    if (dt23 == 1380 && res[1] == 'v') res[2] = 'v';

    for (int i = 0; i < 3; i++) cout << res[i] << "\n";
    if (res[0] == 'v' && res[1] == 'v' && res[2] == 'v') cout << "sucesso";
    else cout << "falha";

    return 0;
}