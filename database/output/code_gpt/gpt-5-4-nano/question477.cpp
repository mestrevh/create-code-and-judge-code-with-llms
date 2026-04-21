/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long forca, inteligencia, destreza, furtividade, peso;
    if (!(cin >> forca >> inteligencia >> destreza >> furtividade >> peso)) return 0;

    if (forca > 10 && inteligencia < 5 && destreza < 5 && furtividade < 5 && peso > 5) {
        cout << "Orc\n";
    } else if (forca > 5 && inteligencia > 5 && destreza > 5 && furtividade > 5 && peso < 5) {
        cout << "Paladin\n";
    } else if (forca < 5 && inteligencia > 5 && destreza >= 5 && furtividade > 5 && peso < 5) {
        cout << "Mage\n";
    } else if (forca > 5 && inteligencia <= 5 && destreza > 5 && furtividade <= 5 && peso > 5) {
        cout << "Knight\n";
    } else {
        cout << "Knight\n";
    }

    return 0;
}