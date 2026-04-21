/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x1, y1, x2, y2, S, x3, y3;
    if (!(cin >> x1 >> y1 >> x2 >> y2 >> S >> x3 >> y3)) return 0;

    long long dx = x2 - x1;
    long long dy = y2 - y1;
    long long cx = x3 - x1;
    long long cy = y3 - y1;

    long long cross = dx * cy - dy * cx;

    bool pegue = false;
    if (S == 0) {
        pegue = (cross > 0);
    } else {
        pegue = (cross < 0);
    }

    cout << (pegue ? 'S' : 'N') << "\n";
    return 0;
}