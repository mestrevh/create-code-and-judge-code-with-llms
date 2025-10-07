/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

bool ehQuadradoMagico(const vector<vector<int>>& matriz, int N) {
    int soma = 0;
    for (int j = 0; j < N; j++) soma += matriz[0][j];

    // Verifica linhas
    for (int i = 0; i < N; i++) {
        int somaLinha = 0;
        for (int j = 0; j < N; j++) somaLinha += matriz[i][j];
        if (somaLinha != soma) return false;
    }

    // Verifica colunas
    for (int j = 0; j < N; j++) {
        int somaColuna = 0;
        for (int i = 0; i < N; i++) somaColuna += matriz[i][j];
        if (somaColuna != soma) return false;
    }

    // Verifica diagonal principal
    int somaDiagonal1 = 0, somaDiagonal2 = 0;
    for (int i = 0; i < N; i++) {
        somaDiagonal1 += matriz[i][i];
        somaDiagonal2 += matriz[i][N - 1 - i];
    }
    if (somaDiagonal1 != soma || somaDiagonal2 != soma) return false;

    return true;
}

int main() {
    int K;
    cin >> K;

    while (K--) {
        int N;
        cin >> N;
        vector<vector<int>> matriz(N, vector<int>(N));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> matriz[i][j];

        if (ehQuadradoMagico(matriz, N)) 
            cout << "Eh quadrado magico!!!" << endl;
        else 
            cout << "Nao eh!!!" << endl;
    }

    return 0;
}
