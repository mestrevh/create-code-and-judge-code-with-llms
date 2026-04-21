/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problema: Permutador de Trem (Train Swapping / UVA 299)
 * O problema solicita o número mínimo de trocas adjacentes para ordenar um array.
 * Esse valor é equivalente ao número de inversões no array.
 * Com L <= 50, uma solução O(L^2) é ideal e extremamente rápida.
 */

int main() {
    // Otimização de entrada e saída padrão para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L;
    // O loop processa cada caso de teste. L é o comprimento do comboio.
    while (cin >> L) {
        if (L <= 0) {
            // Se L for 0, conforme as restrições 0 < L <= 50 não deve ocorrer, 
            // mas tratamos por segurança em sistemas de maratona.
            if (L == 0) cout << "A melhor troca leva 0 passos" << "\n";
            continue;
        }

        vector<int> vagao(L);
        for (int i = 0; i < L; ++i) {
            cin >> vagao[i];
        }

        int swaps = 0;
        // Contagem de inversões (equivalente ao número de trocas no Bubble Sort)
        // Complexidade O(L^2), que para L=50 resulta em no máximo 1225 iterações.
        for (int i = 0; i < L; ++i) {
            for (int j = i + 1; j < L; ++j) {
                if (vagao[i] > vagao[j]) {
                    swaps++;
                }
            }
        }

        // Saída conforme o formato especificado: "A melhor troca leva S passos"
        cout << "A melhor troca leva " << swaps << " passos" << "\n";
    }

    return 0;
}

// Complexidade de Tempo: O(L^2) por caso de teste
// Complexidade de Espaço: O(L) para armazenar os vagões