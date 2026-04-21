/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dia, mes, ano;
    if (!(cin >> dia >> mes >> ano)) return 0;

    auto inRange = [](int v, int lo, int hi) { return v >= lo && v <= hi; };

    if (!(inRange(dia, 1, 31) && inRange(mes, 1, 12) && inRange(ano, 1900, 2020))) {
        cout << "Dia, mês ou ano inexistente";
        return 0;
    }

    auto leap = [&](int y) {
        if (y % 400 == 0) return true;
        if (y % 100 == 0) return false;
        return (y % 4 == 0);
    };

    if (mes == 2) {
        int maxd = leap(ano) ? 29 : 28;
        if (dia < 1 || dia > maxd) {
            cout << "Esse dia não existe nesse mês";
            return 0;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia < 1 || dia > 30) {
            cout << "Esse dia não existe nesse mês";
            return 0;
        }
    } else {
        if (dia < 1 || dia > 31) {
            cout << "Esse dia não existe nesse mês";
            return 0;
        }
    }

    cout << "Data Validada";
    return 0;
}