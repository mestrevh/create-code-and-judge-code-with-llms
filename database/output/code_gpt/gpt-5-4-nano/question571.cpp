/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtd;
    int v;
    if (!(cin >> qtd >> v)) return 0;

    long long totalCentavos = 0;
    long long pagoCentavos = 0;

    for (int i = 0; i < qtd; i++) {
        long long val = v;
        if (val == 2) {
            pagoCentavos += 325;
            totalCentavos += 200;
        } else if (val == 5) {
            pagoCentavos += 325;
            totalCentavos += 500;
        } else if (val == 10) {
            pagoCentavos += 325;
            totalCentavos += 1000;
        } else if (val == 20) {
            pagoCentavos += 325;
            totalCentavos += 2000;
        } else {
            return 0;
        }
    }

    long long troco = totalCentavos - pagoCentavos;
    long long refeicoes = troco / 325;
    cout << refeicoes << "\n";
    return 0;
}