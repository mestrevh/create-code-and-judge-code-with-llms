/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; i++) {
        string name;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        double ab1, ab2;
        cin >> ab1 >> ab2;

        double media = (ab1 + ab2) / 2.0;
        string situacao = (media >= 7.0 ? "AP" : "RP");

        cout << "Nome:  " << name << "\n";
        cout << "AB1: " << fixed << setprecision(2) << ab1 << "\n";
        cout << "AB2: " << fixed << setprecision(2) << ab2 << "\n";
        cout << "Media: " << fixed << setprecision(2) << media << "\n";
        cout << "Situacao: " << situacao;
        if (i + 1 < n) cout << "\n";
    }

    return 0;
}