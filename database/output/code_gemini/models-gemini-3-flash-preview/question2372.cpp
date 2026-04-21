/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Função que recebe uma matriz de inteiros e suas dimensões,
 * retornando a contagem de elementos pares.
 */
int contarItensPares(const vector<vector<int>>& M, int L, int C) {
    int contador = 0;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            // Um número é par se o resto da divisão por 2 for zero
            if (M[i][j] % 2 == 0) {
                contador++;
            }
        }
    }
    return contador;
}

int main() {
    // Otimização de I/O padrão para programação competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, C;
    
    // Leitura das dimensões da matriz
    if (!(cin >> L >> C)) return 0;

    // Alocação da matriz M com L linhas e C colunas
    // Nota: Em cenários de altíssima performance, um vetor simples de tamanho L*C
    // poderia ser utilizado para melhorar a localidade de cache.
    vector<vector<int>> M(L, vector<int>(C));

    // Leitura dos L x C valores da matriz
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> M[i][j];
        }
    }

    // Chamada da função e exibição do resultado
    cout << contarItensPares(M, L, C) << endl;

    return 0;
}
