/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Função para verificar se um número é primo.
 * Complexidade: O(sqrt(N))
 */
bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    // Otimização de I/O padrão para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int val, prime_count = 0;
    
    // O problema especifica três números inteiros
    for (int i = 0; i < 3; ++i) {
        if (cin >> val) {
            if (is_prime(val)) {
                prime_count++;
            }
        }
    }

    // Regras de decisão baseadas na contagem de números primos
    if (prime_count == 0) {
        cout << "Seguro\n";
    } else if (prime_count == 1) {
        cout << "Possível Risco\n";
    } else {
        cout << "Perigo\n";
    }

    return 0;
}