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
    string cidade;
    int quartos;
    if (!(cin >> n)) return 0;
    cin >> cidade >> quartos;

    string c = cidade;
    for (char &ch : c) ch = (char)toupper((unsigned char)ch);

    double casa = 0.0;
    double barco = n * 75.0;
    double parque = n * 60.0;

    if (c == "PIPA") {
        casa = (quartos == 2) ? 600.0 : 900.0;
    } else {
        if (quartos == 3) casa = 950.0;
        else casa = 1120.0;
    }

    double total = casa + barco + parque;
    double porPessoa = total / n;

    cout << fixed << setprecision(2) << total << "\n" << fixed << setprecision(2) << porPessoa << "\n";
    return 0;
}