/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y;
    if (!(cin >> x >> y)) return 0;

    if (x == 0 && y == 0) {
        cout << "origem\n";
    } else if (y == 0) {
        cout << "eixo x\n";
    } else if (x == 0) {
        cout << "eixo y\n";
    } else if (x > 0 && y > 0) {
        cout << "primeiro\n";
    } else if (x < 0 && y > 0) {
        cout << "segundo\n";
    } else if (x < 0 && y < 0) {
        cout << "terceiro\n";
    } else {
        cout << "quarto\n";
    }

    return 0;
}