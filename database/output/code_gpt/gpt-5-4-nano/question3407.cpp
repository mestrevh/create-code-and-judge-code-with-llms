/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int op;
    if (!(cin >> op)) return 0;

    double result = 0.0;
    if (op == 1) {
        double a, b;
        cin >> a >> b;
        result = a + b;
    } else if (op == 2) {
        double x;
        cin >> x;
        result = sqrt(x);
    }

    cout << fixed << setprecision(2) << result << "\n";
    return 0;
}