/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> producao(20, vector<int>(12));
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < 12; ++j)
            cin >> producao[i][j];

    int mesInicial, anoInicial, mesFinal, anoFinal;
    cin >> mesInicial >> anoInicial >> mesFinal >> anoFinal;

    int total = 0;

    for (int ano = anoInicial - 2000; ano <= anoFinal - 2000; ++ano) {
        for (int mes = 0; mes < 12; ++mes) {
            if ((ano == anoInicial - 2000 && mes + 1 < mesInicial) ||
                (ano == anoFinal - 2000 && mes + 1 > mesFinal)) {
                continue;
            }
            total += producao[ano][mes];
        }
    }

    cout << total << endl;
    return 0;
}
