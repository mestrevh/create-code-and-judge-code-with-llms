/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double D1, D2, M;
    if (!(cin >> D1)) return 0;
    if (!(cin >> D2)) return 0;
    if (!(cin >> M)) return 0;

    double F = 10.0 * M / (D1 + D2);

    cout << fixed << setprecision(2);
    cout << "Scar conseguiu criar uma frustração " << F << " na turma\n";

    if (F >= 4.0) cout << "Eu matei Mufasa";
    else if (F > 2.0) cout << "Consegui lacaios preciosos";
    else cout << "Mais um fracasso...";
    return 0;
}