/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int I, J;
    cin >> I >> J;
    vector<vector<int>> mat(I, vector<int>(J));
    
    for (int i = 0; i < I; i++)
        for (int j = 0; j < J; j++)
            cin >> mat[i][j];

    for (int i = 0; i < I; i++) {
        int somaLinha = 0;
        for (int j = 0; j < J; j++)
            somaLinha += mat[i][j];
        cout << "Linha " << i << ": " << somaLinha << endl;
    }

    for (int j = 0; j < J; j++) {
        int somaColuna = 0;
        for (int i = 0; i < I; i++)
            somaColuna += mat[i][j];
        cout << "Coluna " << j << ": " << somaColuna << endl;
    }

    if (I == J) {
        int somaDiagonal = 0;
        for (int i = 0; i < I; i++)
            somaDiagonal += mat[i][i];
        cout << "Diagonal principal: " << somaDiagonal << endl;
    }

    return 0;
}
