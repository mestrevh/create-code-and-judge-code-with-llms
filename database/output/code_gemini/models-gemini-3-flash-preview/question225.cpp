/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Problema: Contagem de Inversões
 * Abordagem: Binary Indexed Tree (Fenwick Tree)
 * Complexidade de Tempo: O(N log(max_skill))
 * Complexidade de Espaço: O(max_skill)
 */

const int MAX_SKILL = 100005;
int bit[MAX_SKILL];

void update(int idx, int val) {
    for (; idx < MAX_SKILL; idx += idx & -idx) {
        bit[idx] += val;
    }
}

int query(int idx) {
    int res = 0;
    for (; idx > 0; idx -= idx & -idx) {
        res += bit[idx];
    }
    return res;
}

int main() {
    // Otimização de I/O padrão Maratona/ICPC
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    long long total_pairs = 0;
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        
        /* 
         * Uma dupla válida (A, B) ocorre se A ingressou antes de B e habilidade(A) > habilidade(B).
         * Ao processar o elemento i, as "dançarinas que estão há mais tempo" já foram inseridas no BIT.
         * O número de dançarinas já inseridas é 'i'.
         * O número de dançarinas com habilidade menor ou igual a 's' é query(s).
         * Logo, o número de dançarinas que ingressaram antes e têm habilidade maior que 's' é (i - query(s)).
         */
        total_pairs += (i - query(s));
        
        // Insere a habilidade da dançarina atual no BIT
        update(s, 1);
    }

    cout << total_pairs << "\n";

    return 0;
}