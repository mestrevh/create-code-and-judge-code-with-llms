/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Funcao para verificar se um numero e primo.
 * Numeros menores que 2 nao sao primos.
 */
bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    // Otimizacao de entrada e saida padrao C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Leitura da dimensao da matriz
    if (!(cin >> N)) return 0;

    // Leitura e ordenacao imediata de cada linha da matriz
    vector<vector<int>> mat(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> mat[i][j];
        }
        sort(mat[i].begin(), mat[i].end());
    }

    // Calculo da soma da diagonal principal da matriz ja com as linhas ordenadas
    int sum_diag = 0;
    for (int i = 0; i < N; ++i) {
        sum_diag += mat[i][i];
    }

    // Verificacao de primalidade da soma
    bool prime = is_prime(sum_diag);

    if (prime) {
        // Caso a soma seja primo, imprime a mensagem e a soma
        cout << "A soma resultou em um numero primo!\n";
        cout << sum_diag << "\n";
        
        // Operacao de Transposicao e multiplicacao de impares por 2
        vector<vector<int>> result(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                result[j][i] = mat[i][j];
            }
        }
        
        // Impressao da matriz transposta com a transformacao de impares em pares
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int val = result[i][j];
                if (val % 2 != 0) val *= 2;
                cout << val << (j == N - 1 ? "" : " ");
            }
            cout << "\n";
        }
    } else {
        // Caso a soma nao seja primo, imprime a mensagem e a soma
        cout << "A soma resultou em um numero nao primo!\n";
        cout << sum_diag << "\n";
        
        // Ordenacao da diagonal principal
        vector<int> diag(N);
        for (int i = 0; i < N; ++i) diag[i] = mat[i][i];
        sort(diag.begin(), diag.end());
        for (int i = 0; i < N; ++i) mat[i][i] = diag[i];
        
        // Impressao da matriz com a diagonal ordenada e transformacao de impares em pares
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int val = mat[i][j];
                if (val % 2 != 0) val *= 2;
                cout << val << (j == N - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}