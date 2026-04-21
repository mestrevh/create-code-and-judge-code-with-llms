/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double n1, n2, n3;
    if (!(cin >> n1)) return 0;
    if (!(cin >> n2)) return 0;
    if (!(cin >> n3)) return 0;

    double media = (n1 + n2 + n3) / 3.0;

    cout << fixed << setprecision(1);

    if (media >= 7.0) {
        cout << "Aprovado com media " << media;
    } else if (media >= 5.0 && media < 7.0) {
        cout << "Recuperacao com media " << media;
    } else {
        cout << "Reprovado com media " << media;
    }

    return 0;
}