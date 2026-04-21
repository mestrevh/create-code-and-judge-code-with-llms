/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

/**
 * Grande Mestre em Programação Competitiva
 * Solução para o problema de Descriptografia.
 * Complexidade de tempo: O(N), onde N é o tamanho da string.
 * Complexidade de espaço: O(N) devido à pilha de recursão.
 */

void descriptografar(const string& s, int idx) {
    // Caso base: Se |S| = 0, D(S) = ""
    if (idx == (int)s.length()) {
        return;
    }

    // Pi: A posição do carácter na mensagem inicial (1-based index)
    int pi = idx + 1;

    // Lógica baseada na definição recursiva fornecida
    if (s[idx] == '*') {
        // Se o primeiro elemento for '*', D(S) = (Pi + D(S-1))
        cout << "(" << pi;
        descriptografar(s, idx + 1);
        cout << ")";
    } else if (s[idx] == '-') {
        // Se o primeiro elemento for '-', D(S) = Pi + D(S-1)
        cout << pi;
        descriptografar(s, idx + 1);
    }
}

int main() {
    // Otimização de I/O padrão C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    // Leitura da string criptografada
    if (cin >> s) {
        descriptografar(s, 0);
        cout << "\n";
    }

    return 0;
}