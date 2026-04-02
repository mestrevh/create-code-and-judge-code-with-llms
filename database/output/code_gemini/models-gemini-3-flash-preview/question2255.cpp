/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Função iterativa que calcula a quantidade de dígitos de um número natural n.
 * Utiliza um laço do-while para garantir que o número 0 seja contabilizado como tendo 1 dígito.
 * Complexidade de Tempo: O(log10 n)
 * Complexidade de Espaço: O(1)
 */
int contar_digitos(long long n) {
    int contador = 0;
    do {
        contador++;
        n /= 10;
    } while (n > 0);
    return contador;
}

int main() {
    // Otimização de I/O padrão para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (cin >> n) {
        cout << contar_digitos(n) << "\n";
    }

    return 0;
}