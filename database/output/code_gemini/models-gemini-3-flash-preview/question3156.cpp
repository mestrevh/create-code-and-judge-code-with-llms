/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Problema: Corona Ep 5
 * Propriedade de Samuel: Soma dos divisores de X e o seu sucessor (X+1).
 * Matematicamente, sigma(X) = X + 1 se e somente se X for um número primo.
 * A tarefa consiste em encontrar todos os primos no intervalo fechado [i, j].
 */

bool is_prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long k = 5; k * k <= n; k += 6) {
        if (n % k == 0 || n % (k + 2) == 0) return false;
    }
    return true;
}

int main() {
    // Otimização de I/O para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long i, j;
    
    // Leitura do range [i, j]
    // O uso de while permite processar múltiplos casos de teste se fornecidos
    while (cin >> i >> j) {
        // Conforme a descrição: i <= X <= j
        // Se i for maior que j, o intervalo matematicamente é vazio
        for (long long x = i; x <= j; ++x) {
            if (is_prime(x)) {
                cout << x << "\n";
            }
        }
    }

    return 0;
}