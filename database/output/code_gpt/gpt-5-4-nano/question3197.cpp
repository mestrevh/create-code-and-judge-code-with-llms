/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double qtd2L, qtd600ml, qtd350ml;
    if (!(cin >> qtd2L)) return 0;
    cin >> qtd600ml >> qtd350ml;

    long double totalLitros = qtd2L * 2.0L + qtd600ml * 0.6L + qtd350ml * 0.35L;
    cout << fixed << setprecision(1) << (double)totalLitros;
    return 0;
}