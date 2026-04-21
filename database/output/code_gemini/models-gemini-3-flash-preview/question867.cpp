/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Problema: Quais letras aparecem
 * Complexidade de Tempo: O(N), onde N é o número de caracteres na entrada.
 * Complexidade de Espaço: O(1), pois usamos um array de tamanho fixo (26).
 */

int main() {
    // Otimização de I/O padrão para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Vetor de booleanos para registrar a presença de cada letra (a-z)
    bool seen[26] = {false};
    char c;

    // Leitura caractere por caractere até o fim da entrada (EOF)
    while (cin.get(c)) {
        // Verifica se é uma letra minúscula
        if (c >= 'a' && c <= 'z') {
            seen[c - 'a'] = true;
        } 
        // Verifica se é uma letra maiúscula e mapeia para a mesma posição
        else if (c >= 'A' && c <= 'Z') {
            seen[c - 'A'] = true;
        }
    }

    // Impressão das letras encontradas em ordem alfabética (crescente)
    for (int i = 0; i < 26; ++i) {
        if (seen[i]) {
            cout << (char)('a' + i) << "\n";
        }
    }

    return 0;
}