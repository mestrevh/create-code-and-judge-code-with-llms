/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double temp;
    char ans;
    if (!(cin >> temp)) return 0;
    if (!(cin >> ans)) return 0;

    if (ans != 'S' && ans != 'N') {
        cout << "Erro";
        return 0;
    }

    if (temp >= 37.0) {
        if (ans == 'S') cout << "Exames Especiais";
        else cout << "Exames Basicos";
    } else {
        if (ans == 'S') cout << "Exames Basicos";
        else cout << "Liberado";
    }

    return 0;
}