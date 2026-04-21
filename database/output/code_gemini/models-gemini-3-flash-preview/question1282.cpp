/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problema: Quadrado Mágico
 * Complexidade de Tempo: O(N*M) - Leitura e verificação da matriz.
 * Complexidade de Espaço: O(N*M) - Armazenamento da matriz.
 */

int main() {
    // Otimização de I/O padrão C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    // Tenta ler as dimensões da matriz
    if (!(cin >> N >> M)) {
        return 0;
    }

    // Por definição, um quadrado mágico deve ser uma matriz quadrada (N == M)
    if (N != M || N <= 0) {
        // Se houver dados de matriz remanescentes no buffer, consumi-los não é estritamente
        // necessário para o julgamento, mas N != M falha na propriedade de quadrado mágico.
        cout << "A matriz recebida nao e magica." << endl;
        return 0;
    }

    // Alocação da matriz
    vector<vector<long long>> mat(N, vector<long long>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!(cin >> mat[i][j])) break;
        }
    }

    // Calcula a soma de referência (primeira linha)
    long long targetSum = 0;
    for (int j = 0; j < N; ++j) {
        targetSum += mat[0][j];
    }

    bool isMagic = true;

    // 1. Verificar todas as linhas
    for (int i = 0; i < N; ++i) {
        long long currentSum = 0;
        for (int j = 0; j < N; ++j) {
            currentSum += mat[i][j];
        }
        if (currentSum != targetSum) {
            isMagic = false;
            break;
        }
    }

    // 2. Verificar todas as colunas
    if (isMagic) {
        for (int j = 0; j < N; ++j) {
            long long currentSum = 0;
            for (int i = 0; i < N; ++i) {
                currentSum += mat[i][j];
            }
            if (currentSum != targetSum) {
                isMagic = false;
                break;
            }
        }
    }

    // 3. Verificar as duas diagonais
    if (isMagic) {
        long long mainDiagSum = 0;
        long long secDiagSum = 0;
        for (int i = 0; i < N; ++i) {
            mainDiagSum += mat[i][i];
            secDiagSum += mat[i][N - 1 - i];
        }
        if (mainDiagSum != targetSum || secDiagSum != targetSum) {
            isMagic = false;
        }
    }

    // Saída baseada na flag de validação
    if (isMagic) {
        cout << "A matriz recebida e magica." << endl;
    } else {
        cout << "A matriz recebida nao e magica." << endl;
    }

    return 0;
}