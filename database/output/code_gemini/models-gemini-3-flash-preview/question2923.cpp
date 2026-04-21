/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problema: Aninha e os Triângulos
 * 
 * Descrição: Encontrar a área (número de 1s) do maior triângulo isósceles 
 * preenchido com '1' em uma matriz binária. O triângulo deve estar apontando 
 * para cima e o menor triângulo válido deve conter no mínimo 4 números '1' 
 * (altura h >= 2).
 * 
 * Abordagem: Programação Dinâmica.
 * Definimos dp[i][j] como a altura máxima de um triângulo isósceles cujo 
 * ápice está na posição (i, j).
 * Se mat[i][j] == 1, dp[i][j] = 1 + min(dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]).
 * A área de um triângulo de altura H é dada por H^2.
 * 
 * Complexidade de Tempo: O(M * N)
 * Complexidade de Espaço: O(M * N)
 */

int main() {
    // Otimização de I/O padrão em C++ para programação competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    // Leitura das dimensões da matriz
    if (!(cin >> m >> n)) return 0;

    // Verificação de matriz vazia ou dimensões inválidas
    if (m <= 0 || n <= 0) {
        cout << 0 << endl;
        return 0;
    }

    // Armazenamento da matriz em um vetor linear para melhor localidade de cache
    vector<int> mat(m * n);
    for (int i = 0; i < m * n; ++i) {
        if (!(cin >> mat[i])) break;
    }

    // dp[i * n + j] armazena a altura do maior triângulo isósceles com ápice em (i, j)
    vector<int> dp(m * n, 0);
    int max_h = 0;

    // Inicialização da última linha: a altura máxima possível para um ápice aqui é 1
    for (int j = 0; j < n; ++j) {
        if (mat[(m - 1) * n + j] == 1) {
            dp[(m - 1) * n + j] = 1;
            if (max_h < 1) max_h = 1;
        }
    }

    // Processamento da matriz de baixo para cima para construir os triângulos
    for (int i = m - 2; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i * n + j] == 1) {
                // Para formar um triângulo de altura H com ápice em (i, j),
                // precisamos de triângulos de altura H-1 nas três posições abaixo.
                if (j > 0 && j < n - 1) {
                    int h_esq = dp[(i + 1) * n + (j - 1)];
                    int h_meio = dp[(i + 1) * n + j];
                    int h_dir = dp[(i + 1) * n + (j + 1)];
                    dp[i * n + j] = 1 + min({h_esq, h_meio, h_dir});
                } else {
                    // Se estiver nas bordas laterais, a altura máxima é 1
                    dp[i * n + j] = 1;
                }
                
                // Atualiza a maior altura encontrada
                if (dp[i * n + j] > max_h) {
                    max_h = dp[i * n + j];
                }
            }
        }
    }

    // O problema define que o menor triângulo válido tem 4 '1's (altura 2).
    // Triângulos de altura 1 (apenas um '1') não devem ser considerados.
    if (max_h < 2) {
        cout << 0 << endl;
    } else {
        // A quantidade de '1's em um triângulo de altura H é H^2.
        // H + (H-1) + ... + 1 não é o caso aqui. A progressão é 1, 3, 5, ..., 2H-1.
        // A soma dessa PA é H^2.
        long long area = (long long)max_h * max_h;
        cout << area << endl;
    }

    return 0;
}