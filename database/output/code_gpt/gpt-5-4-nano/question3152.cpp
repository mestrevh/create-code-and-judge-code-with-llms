/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ax, ay, bx, by, cx, cy;
    if (!(cin >> ax >> ay >> bx >> by >> cx >> cy)) return 0;

    auto dist2 = [&](long long x1, long long y1, long long x2, long long y2) -> long long {
        long long dx = x1 - x2;
        long long dy = y1 - y2;
        return dx * dx + dy * dy;
    };

    long long ab = dist2(ax, ay, bx, by);
    long long ac = dist2(ax, ay, cx, cy);
    long long bc = dist2(bx, by, cx, cy);

    long long minD2 = 4;
    if (ab >= minD2 && ac >= minD2 && bc >= minD2) {
        cout << "POSICAO VALIDA";
    } else {
        cout << "POSICAO INVALIDA";
    }
    return 0;
}