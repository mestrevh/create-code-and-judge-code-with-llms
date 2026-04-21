/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b;
    if (!(cin >> a >> b)) return 0;
    char op;
    cin >> op;

    cout << fixed << setprecision(2);

    if (op == '+') {
        cout << a << " + " << b << " = " << (a + b);
    } else if (op == '-') {
        cout << a << " - " << b << " = " << (a - b);
    } else if (op == '*') {
        cout << a << " * " << b << " = " << (a * b);
    } else if (op == '/') {
        cout << a << " / " << b << " = " << (a / b);
    } else {
        cout << "A operacao " << op << " eh invalida!";
    }

    return 0;
}