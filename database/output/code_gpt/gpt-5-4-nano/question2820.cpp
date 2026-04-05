/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Digite as distancias percorridas separadas por ENTER\n";

    int dias = 7;
    double d;
    int metaDias = 0;

    for (int i = 0; i < dias; i++) {
        if (!(cin >> d)) return 0;
        if (d >= 8.0) metaDias++;
    }

    cout << "Meta alcancada em " << metaDias << " dias\n";

    if (metaDias >= 5) cout << "Desempenho otimo";
    else if (metaDias >= 3) cout << "Desempenho bom";
    else cout << "Desempenho ruim";

    return 0;
}