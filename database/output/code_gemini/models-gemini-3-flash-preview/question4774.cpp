/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <climits>

using namespace std;

/**
 * Funcao para verificar se um numero e primo.
 * Complexidade: O(sqrt(N))
 */
bool is_prime(long long n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

/**
 * Funcao para calcular a soma dos divisores de n, excluindo o proprio n.
 * Complexidade: O(sqrt(N))
 */
long long sum_divisors(long long n) {
    if (n <= 1) return 0;
    long long sum = 1; // 1 e sempre divisor para n > 1
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n) {
                sum += n / i;
            }
        }
    }
    return sum;
}

int main() {
    // Otimizacao de I/O para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    long long max_prime = -1;
    long long min_sum = LLONG_MAX;
    bool found_prime = false;
    bool found_non_prime = false;

    // Leitura da sequencia ate encontrar um numero <= 0
    while (cin >> n && n > 0) {
        if (is_prime(n)) {
            if (!found_prime || n > max_prime) {
                max_prime = n;
            }
            found_prime = true;
        } else {
            long long s = sum_divisors(n);
            if (!found_non_prime || s < min_sum) {
                min_sum = s;
            }
            found_non_prime = true;
        }
    }

    // Saida referente aos numeros primos
    if (found_prime) {
        cout << "Maior numero primo: " << max_prime << "\n";
    } else {
        cout << "Nenhum numero primo foi digitado\n";
    }

    // Saida referente aos numeros nao primos (conforme formato dos casos de teste)
    if (found_non_prime) {
        cout << "A Menor soma dos divisores: " << min_sum << "\n";
    } else {
        cout << "Nenhum numero nao primo foi digitado\n";
    }

    // Verificacao da condicao de campeao
    // "maior numero primo seja maior que 3 vezes a menor soma dos numeros nao primos"
    if (found_prime && found_non_prime && (max_prime > 3 * min_sum)) {
        cout << "Deu a logica, computos campeao!\n";
    } else {
        cout << "eh mafiaaaaa!\n";
    }

    return 0;
}