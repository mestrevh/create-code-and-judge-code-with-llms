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
    if (!(cin >> a >> b)) return 0;

    double prod = a * b;
    double ratio = a / b;

    cout << fixed << setprecision(4);
    cout << "Produto: " << prod << "\n";
    cout << "Razao: " << ratio << "\n";

    return 0;
}