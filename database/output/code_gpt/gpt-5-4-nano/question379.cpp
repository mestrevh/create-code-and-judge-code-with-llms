/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dias = 7;
    double x;
    int cumpriu = 0;

    for (int i = 0; i < dias; i++) {
        if (!(cin >> x)) return 0;
        if (x >= 8.0) cumpriu++;
    }

    if (cumpriu >= 5) cout << "Desempenho otimo";
    else if (cumpriu >= 3) cout << "Desempenho razoavel";
    else cout << "Desempenho ruim";

    return 0;
}