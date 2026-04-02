/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Função recursiva para contar ocorrências do dígito x no número n.
 * Complexidade de tempo: O(log10(n))
 * Complexidade de espaço: O(log10(n)) devido à pilha de recursão
 */
int contar_ocorrencias(long long n, int x) {
    // Caso base: se o número tem apenas um dígito
    if (n < 10) {
        return (n == x ? 1 : 0);
    }
    // Passo recursivo: verifica o último dígito e processa o restante do número
    return (n % 10 == x ? 1 : 0) + contar_ocorrencias(n / 10, x);
}

int main() {
    // Otimização de I/O padrão competitivo
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    int x;

    // Leitura dos dados de entrada
    if (!(cin >> n >> x)) return 0;

    // Chamada da única função permitida e exibição do resultado
    cout << contar_ocorrencias(n, x) << endl;

    return 0;
}