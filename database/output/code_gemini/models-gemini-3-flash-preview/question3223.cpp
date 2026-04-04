/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problema: Encontrar a soma mínima de K tábuas consecutivas.
 * Complexidade de Tempo: O(N) - Percorremos o array duas vezes (uma para leitura, outra para o sliding window).
 * Complexidade de Espaço: O(N) - Armazenamos as alturas em um vetor.
 * 
 * N e K podem chegar a 2 * 10^6. A soma das alturas pode ultrapassar o limite de um int (2^31-1),
 * pois (2*10^6) * (2*10^6) = 4*10^12. Portanto, usamos 'long long' para a soma.
 */

int main() {
    // Otimização de Entrada e Saída
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    // Reservamos memória para as alturas para evitar realocações
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    // Soma inicial dos primeiros K elementos
    long long current_sum = 0;
    for (int i = 0; i < k; ++i) {
        current_sum += h[i];
    }

    long long min_sum = current_sum;
    int best_idx = 1; // Índice 1-based do início da sequência mínima

    /**
     * Técnica: Janela Deslizante (Sliding Window)
     * Ao mover a janela uma posição para a direita:
     * - Subtraímos o elemento que sai (h[i-k])
     * - Adicionamos o elemento que entra (h[i])
     */
    for (int i = k; i < n; ++i) {
        current_sum = current_sum - h[i - k] + h[i];
        
        // Se encontrarmos uma soma estritamente menor, atualizamos o índice.
        // O uso de '<' garante que mantemos o menor índice em caso de empates.
        if (current_sum < min_sum) {
            min_sum = current_sum;
            best_idx = i - k + 2; // (i-k+1) seria o início 0-based, logo +1 para 1-based
        }
    }

    cout << best_idx << "\n";

    return 0;
}