/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * Grande Mestre em Programação Competitiva.
 * Solução para o problema da Série.
 * Complexidade de Tempo: O(N)
 * Complexidade de Espaço: O(N)
 */

// Função para calcular um termo individual, se necessário.
// No entanto, para otimização O(N), calcularemos os termos iterativamente.
double calcular_termo_especifico(int n) {
    double fatorial = 1.0;
    for (int i = 1; i <= n + 1; ++i) {
        fatorial *= (double)i;
    }
    return fatorial / sqrt(2.0 * n + 3.0);
}

// Função principal de processamento da série.
void processar_e_exibir_serie(int N) {
    if (N <= 0) return;

    vector<double> termos(N);
    double soma_total = 0.0;
    double fatorial_atual = 1.0;

    // Cálculo dos termos e da soma em O(N)
    for (int i = 0; i < N; ++i) {
        fatorial_atual *= (i + 1);
        // A fórmula identificada a partir dos casos de teste é:
        // T(i) = (i+1)! / sqrt(2*i + 3)
        termos[i] = fatorial_atual / sqrt(2.0 * i + 3.0);
        soma_total += termos[i];
    }

    // Exibição do resultado da soma
    cout << "S: " << fixed << setprecision(12) << soma_total << "\n";

    // Exibição dos termos em ordem inversa, exceto o último termo (N-1)
    // conforme observado no padrão dos casos de teste fornecidos.
    for (int i = N - 2; i >= 0; --i) {
        cout << fixed << setprecision(12) << termos[i] << "\n";
    }
}

int main() {
    // Otimização de I/O padrão em C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (cin >> N) {
        processar_e_exibir_serie(N);
    }

    return 0;
}