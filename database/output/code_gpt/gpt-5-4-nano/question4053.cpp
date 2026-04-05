/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double n1, n2;
    if (!(cin >> n1 >> n2)) return 0;

    cout << fixed << setprecision(2);
    cout << n1 << " + " << n2 << " = " << (n1 + n2) << "\n";
    cout << n1 << " - " << n2 << " = " << (n1 - n2) << "\n";
    cout << n1 << " * " << n2 << " = " << (n1 * n2) << "\n";
    cout << n1 << " / " << n2 << " = " << (n1 / n2) << "\n";

    return 0;
}