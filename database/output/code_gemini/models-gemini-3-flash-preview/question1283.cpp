/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problema: Multiplicação de Matrizes e Verificação de Matriz Identidade.
 * Complexidade: O(N^3) no tempo, O(N^2) no espaço.
 * Otimização: Cache-friendly loop order (i-k-j) para multiplicação.
 */

int main() {
    // Otimização de I/O padrão C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Alocação dinâmica para lidar com N variável
    vector<vector<long long>> a(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<long long>> b(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> b[i][j];
        }
    }

    // Matriz de resultado inicializada com zeros
    vector<vector<long long>> c(n, vector<long long>(n, 0));

    // Multiplicação de matrizes com otimização de localidade de cache (i-k-j)
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            long long aik = a[i][k];
            for (int j = 0; j < n; ++j) {
                c[i][j] += aik * b[k][j];
            }
        }
    }

    // Verificação de identidade e impressão do resultado
    bool is_identity = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Imprime o elemento da matriz resultado
            cout << c[i][j] << (j == n - 1 ? "" : " ");
            
            // Verifica propriedades da matriz identidade
            if (i == j) {
                if (c[i][j] != 1) is_identity = false;
            } else {
                if (c[i][j] != 0) is_identity = false;
            }
        }
        cout << "\n";
    }

    // Saída final baseada na verificação
    if (is_identity) {
        cout << "Acertou" << endl;
    } else {
        cout << "Errou" << endl;
    }

    return 0;
}