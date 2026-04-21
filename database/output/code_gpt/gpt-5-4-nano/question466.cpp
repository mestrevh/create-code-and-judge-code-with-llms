/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string nome;
    bool firstRead = true;

    string melhorNome;
    long long melhorDist = -1;
    long double melhorCustoDist = -1;

    while (cin >> nome) {
        if (!nome.empty() && (tolower(nome[0]) == 'f' || nome.size() >= 3)) {
            string lower = nome;
            for (char &c : lower) c = (char)tolower((unsigned char)c);
            if (lower == "fim") break;
        }

        long long dist;
        long double preco;
        if (!(cin >> dist >> preco)) break;

        long double custoIdaVolta = 2.0L * preco;
        if (custoIdaVolta <= 300.0L + 1e-12L) {
            if (firstRead) {
                melhorNome = nome;
                melhorDist = dist;
                melhorCustoDist = dist;
                firstRead = false;
            } else {
                if (dist > melhorDist) {
                    melhorNome = nome;
                    melhorDist = dist;
                    melhorCustoDist = dist;
                }
            }
        }

        firstRead = false;
    }

    if (melhorDist < 0) {
        cout << "SEM DESTINO";
        return 0;
    }

    for (char c : melhorNome) cout << (char)toupper((unsigned char)c);
    return 0;
}