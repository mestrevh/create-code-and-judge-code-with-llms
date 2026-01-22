/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int linhas, colunas;
    cin >> linhas >> colunas;

    if (linhas <= 0 || colunas <= 0 || linhas != colunas) {
        cout << "erro" << endl;
        return 0;
    }

    vector<vector<int>> matriz(linhas, vector<int>(colunas));
    for (int i = 0; i < linhas; ++i)
        for (int j = 0; j < colunas; ++j)
            cin >> matriz[i][j];

    vector<int> maxPorLinha(linhas, numeric_limits<int>::min());
    vector<int> maxPorColuna(colunas, numeric_limits<int>::min());
    int maxGlobal = numeric_limits<int>::min();
    int somaDiagonalPrincipal = 0;
    int diffDiagonalSecundaria = 0;

    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (matriz[i][j] > maxPorLinha[i])
                maxPorLinha[i] = matriz[i][j];
            if (matriz[i][j] > maxPorColuna[j])
                maxPorColuna[j] = matriz[i][j];
            if (matriz[i][j] > maxGlobal)
                maxGlobal = matriz[i][j];
            if (i == j && matriz[i][j] > 0)
                somaDiagonalPrincipal += matriz[i][j];
            if (i + j == linhas - 1)
                diffDiagonalSecundaria -= matriz[i][j];
        }
    }

    cout << "[";
    for (int i = 0; i < maxPorLinha.size(); ++i) {
        cout << maxPorLinha[i];
        if (i < maxPorLinha.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "[";
    for (int i = 0; i < maxPorColuna.size(); ++i) {
        cout << maxPorColuna[i];
        if (i < maxPorColuna.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << maxGlobal << endl;
    cout << somaDiagonalPrincipal << endl;
    cout << diffDiagonalSecundaria << endl;

    return 0;
}
