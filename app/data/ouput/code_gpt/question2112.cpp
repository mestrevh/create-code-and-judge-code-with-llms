/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matriz(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matriz[i][j];

    bool criterio = true;

    for (int j = 0; j < n; ++j) {
        double soma = 0.0;
        for (int i = 0; i < n; ++i) {
            if (i != j) {
                soma += abs(matriz[i][j]);
            }
        }
        double alfa = soma / abs(matriz[j][j]);
        if (alfa >= 1) {
            criterio = false;
            break;
        }
    }

    cout << (criterio ? "SIM\n" : "NAO\n");
    return 0;
}
