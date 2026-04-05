/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Digite a soma dos dados em cada rodada separados por ENTER:\n";
    int a[3];
    for (int i = 0; i < 3; i++) {
        if (!(cin >> a[i])) return 0;
        if (a[i] < 2 || a[i] > 12) {
            cout << "Valor invalido";
            return 0;
        }
    }

    bool has2 = (a[0] == 2 || a[1] == 2 || a[2] == 2);
    bool condMaiorOuIgual10OuMenorOuIgual4 = false;
    for (int i = 0; i < 3; i++) {
        if (a[i] >= 10 || a[i] <= 4) {
            condMaiorOuIgual10OuMenorOuIgual4 = true;
            break;
        }
    }

    bool condPar = (a[0] % 2 == 0 || a[1] % 2 == 0 || a[2] % 2 == 0);

    if (!has2 && condMaiorOuIgual10OuMenorOuIgual4 && condPar) cout << "Biu ganhou";
    else cout << "Biu perdeu";

    return 0;
}