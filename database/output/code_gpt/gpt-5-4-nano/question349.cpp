/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int mes, ano;
    if (!(cin >> mes >> ano)) return 0;

    int dias;
    switch (mes) {
        case 1: dias = 31; break;
        case 2: {
            bool bissexto = (ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0);
            dias = bissexto ? 29 : 28;
            break;
        }
        case 3: dias = 31; break;
        case 4: dias = 30; break;
        case 5: dias = 31; break;
        case 6: dias = 30; break;
        case 7: dias = 31; break;
        case 8: dias = 31; break;
        case 9: dias = 30; break;
        case 10: dias = 31; break;
        case 11: dias = 30; break;
        case 12: dias = 31; break;
        default: dias = 0; break;
    }

    cout << dias;
    return 0;
}