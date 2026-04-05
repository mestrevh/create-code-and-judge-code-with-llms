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
    char dir;
    cin >> dir;

    switch (dir) {
        case 'w': y += 1; break;
        case 's': y -= 1; break;
        case 'a': x -= 1; break;
        case 'd': x += 1; break;
        default:
            cout << "Direcao invalida";
            return 0;
    }

    cout << "Nova posicao: " << x << ' ' << y;
    return 0;
}