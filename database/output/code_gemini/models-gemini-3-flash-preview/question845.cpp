/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problema: Willy Ecológico
 * Objetivo: Encontrar a altura máxima H, onde H pertence ao conjunto de alturas das árvores,
 *           tal que a soma das madeiras coletadas (altura_i - H para todas as alturas_i > H)
 *           seja pelo menos M.
 * Complexidade: O(N log N) para ordenação e O(log N) para a busca binária.
 * Espaço: O(N) para armazenar as alturas e somas de sufixo.
 */

int main() {
    // Otimização de I/O para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long m;
    
    // Leitura dos parâmetros N e M
    if (!(cin >> n >> m)) return 0;

    // Leitura das alturas das árvores
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Ordenação necessária para busca binária e cálculo eficiente da madeira
    sort(a.begin(), a.end());

    // Pré-cálculo de somas de sufixo
    // s[i] armazena a soma de todas as alturas do índice i até n-1
    vector<long long> s(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        s[i] = s[i + 1] + a[i];
    }

    // Busca binária sobre os índices do array de alturas ordenado
    int low = 0, high = n - 1;
    long long ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long h_atual = a[mid];

        /**
         * Cálculo da madeira coletada se a serra for configurada na altura h_atual:
         * Como o array está ordenado, todas as árvores com altura maior que h_atual
         * estão nos índices de mid+1 até n-1.
         * A madeira coletada é a soma das alturas dessas árvores menos (quantidade * h_atual).
         */
        long long quantidade_arvores_maiores = (long long)(n - 1 - mid);
        long long madeira_coletada = s[mid + 1] - (quantidade_arvores_maiores * h_atual);

        if (madeira_coletada >= m) {
            // Se conseguimos madeira suficiente, registramos h_atual e tentamos uma altura maior
            ans = h_atual;
            low = mid + 1;
        } else {
            // Se não conseguimos madeira suficiente, precisamos diminuir a altura da serra
            high = mid - 1;
        }
    }

    // Saída do resultado final
    cout << ans << endl;

    return 0;
}