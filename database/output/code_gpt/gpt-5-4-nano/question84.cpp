/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<array<array<long long, 4>, 4>, 4> cnt{};
    int O, D, T;
    while (cin >> O >> D >> T) {
        if (O == 0 && D == 0 && T == 0) break;
        int o = O - 1, d = D - 1, t = T - 1;
        cnt[t][o][d]++;
    }

    auto printMatrix = [&](int t) {
        static const array<string, 3> names = {"Automovel:", "Caminhao:", "Onibus:"};
        cout << names[t] << "\n";
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << cnt[t][i][j] << (j == 3 ? ' ' : ' ');
            }
            cout << "\n";
        }
    };

    printMatrix(0);
    printMatrix(1);
    printMatrix(2);

    long long origemBH = 0;
    for (int d = 0; d < 4; d++) origemBH += cnt[0][0][d] + cnt[1][0][d] + cnt[2][0][d];

    cout << "Origem Belo Horizonte: " << origemBH << "\n";

    long long onibusBrasiliaPetOuBar = 0;
    int o = 3;
    int pet = 1;
    int bar = 3;
    onibusBrasiliaPetOuBar = cnt[2][o][pet] + cnt[2][o][bar];

    cout << "Onibus: Brasilia - Petropolis ou Barbacena: " << onibusBrasiliaPetOuBar << "\n";

    return 0;
}