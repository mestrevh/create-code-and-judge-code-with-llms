/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

long long multiply(long long a, long long b, long long m) {
    if (a == 0 || b == 0) return 0;
    if (a == 1) return b;
    long long half = multiply(a >> 1, b, m);
    if (half > m) return m + 1;
    long long res = half + half;
    if (res > m || res < 0) res = m + 1;
    if (a & 1) {
        res = res + b;
        if (res > m || res < 0) res = m + 1;
    }
    return res;
}

void solve_mike() {
    long long c, m, p;
    if (!(cin >> c >> m >> p)) return;
    if (multiply(c, p, m) <= m) {
        cout << "Sim\n";
    } else {
        cout << "Nao\n";
    }
    solve_mike();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve_mike();
    return 0;
}