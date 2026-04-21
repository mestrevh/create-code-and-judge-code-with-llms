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
    long long M;
    if (!(cin >> N >> M)) return 0;

    vector<string> moves;
    moves.reserve(N * 4);

    long long x = 0, y = 0, z = 0;
    long long used = 0;
    long long delivered = 0;

    for (int i = 1; i <= N * 4; i++) {
        string s;
        cin >> s;
        char Xc = s[0], Yc = s[1], Zc = s[2];
        long long tx = Xc - '0', ty = Yc - '0', tz = Zc - '0';

        string path;
        auto addMove = [&](char c, long long cnt) {
            if (cnt <= 0) return;
            path.append((size_t)cnt, c);
        };

        if (tx > x) addMove('d', tx - x);
        if (tx < x) addMove('e', x - tx);
        x = tx;

        if (ty > y) addMove('c', ty - y);
        if (ty < y) addMove('b', y - ty);
        y = ty;

        if (tz > z) addMove('f', tz - z);
        if (tz < z) addMove('t', z - tz);
        z = tz;

        long long need = (long long)path.size();
        if (used + need <= M) {
            used += need;
            delivered = i;
            cout << path << "\n";
            cout << "Entregue " << i << " no quarto " << Xc << Yc << Zc << " com " << used << " movimentos\n";
        } else {
            cout << "Faltou combustivel e foram entregues " << (i - 1) << " pessoas.\n";
            cout << "Fim do teste. Obrigado Kanye West!\n";
            return 0;
        }
    }

    cout << "Todas as pessoas foram entregues.\n";
    cout << "Fim do teste. Obrigado Kanye West!\n";
    return 0;
}