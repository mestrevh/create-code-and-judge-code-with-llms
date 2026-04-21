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
    string op;
    if (!(cin >> a)) return 0;
    if (!(cin >> b)) return 0;
    if (!(cin >> op)) return 0;

    double res = 0.0;
    if (op == "soma") res = a + b;
    else if (op == "subtracao") res = a - b;
    else if (op == "multiplicacao") res = a * b;
    else if (op == "divisao") res = a / b;

    cout << "resultado = " << fixed << setprecision(2) << res << "\n";
    return 0;
}