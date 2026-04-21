/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Digite um numero de um canal de tv:\n";
    int canal;
    if (!(cin >> canal)) return 0;

    if (canal == 2) cout << "SBT";
    else if (canal == 4) cout << "BAND";
    else if (canal == 6) cout << "REDETV!";
    else if (canal == 9) cout << "RECORD";
    else if (canal == 13) cout << "GLOBO";
    else cout << "Canal inválido";

    return 0;
}