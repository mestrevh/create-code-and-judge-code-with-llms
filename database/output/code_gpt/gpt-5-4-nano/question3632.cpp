/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double x;
    if (!(cin >> x)) return 0;

    bool g1 = false, g2 = false, g3 = false;

    if (x > 0.4) {
        g1 = g2 = g3 = true;
    } else if (x > 0.3) {
        g1 = g2 = true;
    } else if (x > 0.25) {
        g1 = true;
    }

    if (g1) cout << "Grupo 1\n";
    if (g2) cout << "Grupo 2\n";
    if (g3) cout << "Grupo 3\n";

    return 0;
}