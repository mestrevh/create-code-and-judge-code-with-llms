/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

/**
 * Função recursiva para gerar todas as strings binárias de tamanho k sem '1's consecutivos.
 * A ordem de geração (testando '0' antes de '1') garante a ordem lexicográfica.
 */
void generateBinaryStrings(int k, string &current) {
    // Caso base: string atingiu o tamanho desejado
    if (current.length() == k) {
        cout << current << "\n";
        return;
    }

    // Tenta adicionar '0' (sempre permitido)
    current.push_back('0');
    generateBinaryStrings(k, current);
    current.pop_back();

    // Tenta adicionar '1' (apenas se o anterior não for '1')
    if (current.empty() || current.back() == '0') {
        current.push_back('1');
        generateBinaryStrings(k, current);
        current.pop_back();
    }
}

int main() {
    // Otimização de I/O padrão Maratona/ICPC
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    if (cin >> k) {
        // Restrição: 1 <= k <= 20
        if (k >= 1 && k <= 20) {
            string current = "";
            generateBinaryStrings(k, current);
        }
    }

    return 0;
}