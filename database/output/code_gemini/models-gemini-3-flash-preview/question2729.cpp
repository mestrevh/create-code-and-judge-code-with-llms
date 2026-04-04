/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Função que verifica se um número inteiro é menor que zero.
 * @param n O número inteiro a ser verificado.
 * @return 1 se verdadeiro (n < 0), 0 caso contrário.
 */
int is_negative(int n) {
    return (n < 0) ? 1 : 0;
}

int main() {
    // Otimização de I/O padrão para programação competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        if (is_negative(n) == 1) {
            cout << "menor" << endl;
        } else {
            cout << "nao menor" << endl;
        }
    }

    return 0;
}