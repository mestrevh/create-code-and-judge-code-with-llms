/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problema: A Pilha do Mundo Invertido
 * Objetivo: Simular uma pilha com transformações de inversão, corrupção e anulação.
 * Complexidade de Tempo: O(N)
 * Complexidade de Espaço: O(N)
 */

void printStack(const vector<long long>& stack, int startIdx) {
    for (int i = startIdx; i < (int)stack.size(); ++i) {
        cout << stack[i] << " ";
    }
    cout << "\n";
}

int main() {
    // Otimização de I/O para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long vecnaLife;
    int n;

    if (!(cin >> vecnaLife >> n)) return 0;

    // A pilha é preenchida na ordem de entrada: i1, i2, ..., in.
    // O topo da pilha original é o último elemento inserido (in).
    vector<long long> attacks(n);
    for (int i = 0; i < n; ++i) {
        cin >> attacks[i];
    }

    // Printar pilha original (do topo para a base): in, in-1, ..., i1
    for (int i = n - 1; i >= 0; --i) {
        cout << attacks[i] << " ";
    }
    cout << "\n";

    // --- Transformação 1: Inversão ---
    // A pilha original era [i1, i2, ..., in] (base para topo).
    // Inverter a pilha significa que o topo original (in) vira base e a base (i1) vira topo.
    // A nova ordem do topo para a base agora é: i1, i2, i3, ..., in.
    // Portanto, trabalharemos com o vetor na ordem original de entrada.

    // --- Transformação 2: Corrupção Energética ---
    // Ondas com valores pares tornam-se negativas. Ondas ímpares permanecem iguais.
    for (int i = 0; i < n; ++i) {
        if (attacks[i] % 2 == 0) {
            attacks[i] = -attacks[i];
        }
    }

    // --- Transformação 3: Anulação de ondas repetidas no topo ---
    // Enquanto as duas ondas no topo forem iguais, remova ambas.
    int currentTopIdx = 0;
    while (currentTopIdx + 1 < n && attacks[currentTopIdx] == attacks[currentTopIdx + 1]) {
        currentTopIdx += 2;
    }

    // Printar pilha resultante (do topo para a base)
    printStack(attacks, currentTopIdx);

    // Calcular soma dos danos
    long long totalDamage = 0;
    for (int i = currentTopIdx; i < n; ++i) {
        totalDamage += attacks[i];
    }

    // Resultado final
    if (totalDamage >= vecnaLife) {
        cout << "Atravessou o Mundo Invertido com " << totalDamage << " pontos. Vecna foi derrotado!\n";
    } else {
        cout << "Atravessou o Mundo Invertido com " << totalDamage << " pontos. Hawkins esta condenada...\n";
    }

    return 0;
}