/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b;
    int op;
    if (!(cin >> a)) return 0;
    cin >> b >> op;

    double res = 0.0;
    switch (op) {
        case 1: res = a + b; break;
        case 2: res = a - b; break;
        case 3: res = a * b; break;
        case 4: res = a / b; break;
        default: res = 0.0; break;
    }

    cout << fixed << setprecision(3) << res;
    return 0;
}