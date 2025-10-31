/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> valores(N, vector<int>(M));
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> valores[i][j];

    int minValor = INT_MAX;

    for (int j = 0; j < M; j++) {
        int somaEsquerda = 0, somaDireita = 0;
        for (int i = 0; i < N; i++) {
            somaEsquerda += valores[i][j];
            somaDireita += valores[i][M - 1 - j];
        }
        minValor = min(minValor, min(somaEsquerda, somaDireita));
    }

    cout << minValor << endl;
    return 0;
}
