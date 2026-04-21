/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Função iterativa que calcula a soma dos dígitos de um número natural n.
 * Utiliza um único laço de repetição conforme as restrições.
 */
int somarDigitos(long long n) {
    int soma = 0;
    while (n > 0) {
        soma += (n % 10);
        n /= 10;
    }
    return soma;
}

int main() {
    // Otimização de I/O padrão de Maratona de Programação
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (cin >> n) {
        // Caso especial para n = 0, embora o laço trate n > 0
        if (n == 0) {
            cout << 0 << endl;
        } else {
            cout << somarDigitos(n) << endl;
        }
    }

    return 0;
}
