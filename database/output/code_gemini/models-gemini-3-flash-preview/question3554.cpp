/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Funcao para verificar se um numero e primo.
 * Complexidade: O(sqrt(N))
 */
bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    // Otimizacao de E/S padrao para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Leitura do numero N (N > 1)
    if (cin >> n) {
        // A sequencia de Fibonacci: 1, 1, 2, 3, 5, 8, 13, ...
        // Descobrimos o ultimo numero da sequencia antes de N (contando o próprio N).
        // Chamaremos esse valor de last_fib.
        long long a = 1;
        long long b = 1;
        long long last_fib = 1;

        // Geracao dos termos ate que b ultrapasse N
        while (b <= n) {
            last_fib = b;
            long long next = a + b;
            a = b;
            b = next;
        }

        // De acordo com o problema, o i-esimo termo e o valor last_fib.
        // Precisamos encontrar o ultimo primo antes de last_fib (contando ele mesmo).
        // Complexidade: O(distancia_ao_proximo_primo * sqrt(last_fib))
        for (int i = (int)last_fib; i >= 2; --i) {
            if (is_prime(i)) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}